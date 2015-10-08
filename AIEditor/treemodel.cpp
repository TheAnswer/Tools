#include <QtGui>
#include <QAction>

#include "treeitem.h"
#include "treemodel.h"
#include "action.h"
#include "check.h"
#include "composite.h"
#include "node.h"
#include "leaf.h"
#include "actiongroups.h"

TreeModel::TreeModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    root = new Node();
}

TreeModel::~TreeModel()
{
    delete root;
}

/***************************************************************************************************
 * Necessary overrides for reading a tree model
 ***************************************************************************************************/
QVariant TreeModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid()) return QVariant();

	if (role != Qt::DisplayRole && role != Qt::EditRole)
	    return QVariant();

	TreeItem *item = get(index);

	if (item) return item->get(getHeader(index.column()));

	return QVariant();
}

QVariant TreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (orientation != Qt::Horizontal || role != Qt::DisplayRole)
		return QVariant();

	return getHeader(section);
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
	if (parent.isValid() && parent.column() != 0)
		return QModelIndex();

    // only a node item can have a child
    Node *parentItem = dynamic_cast<Node*>(get(parent));
    if (!parentItem) return QModelIndex();

	TreeItem *childItem = parentItem->get(row);

	if (childItem) return createIndex(row, column, childItem);

	return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
	if (!index.isValid())
		return QModelIndex();

	TreeItem *childItem = get(index);
    Node *parentItem = childItem->getParent();

    if (parentItem == root || parentItem == NULL) return QModelIndex();

	return createIndex(parentItem->childNumber(), 0, parentItem);
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    Node *parentItem = dynamic_cast<Node*>(get(parent));

	if (parentItem) return parentItem->count();
	else return 0;
}

int TreeModel::columnCount(const QModelIndex &/*parent*/) const
{
    return 2; // always the same: Name, Type
}
/***************************************************************************************************/


/***************************************************************************************************
 * Necessary overrides for writing a tree model
 ***************************************************************************************************/
Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return 0;

	// allow items to be editable and clickable
	return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

bool TreeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole && role != Qt::DisplayRole) return false;

	TreeItem *item = get(index);
	if (!item) return false;

	QString field = getHeader(index.column());

	bool result = item->set(field, value);

	if (result) emit dataChanged(index, index);

	return result;
}

bool TreeModel::setHeaderData(int /*section*/, Qt::Orientation /*orientation*/, const QVariant &/*value*/, int /*role*/)
{
	return false; // TODO: allow header changes (comes with variable parameter headers)
}

bool TreeModel::insertColumns(int /*position*/, int /*columns*/, const QModelIndex &/*parent*/)
{
	return false; // TODO: allow column insertion (comes with variable parameter headers)
}

bool TreeModel::removeColumns(int /*position*/, int /*columns*/, const QModelIndex &/*parent*/)
{
    return false; // TODO: allow column removal ( comes with variable parameter headers)
}

bool TreeModel::insertRows(int position, int rows, const QModelIndex &parent)
{
    Node *parentItem = dynamic_cast<Node *>(get(parent));

	bool result = true;

	beginInsertRows(parent, position, position + rows - 1);
    if (!parentItem) { // then this is root
        if (!root) root = new Node();
    } else
        result = parentItem->insert(position, rows);
	endInsertRows();

	return result;
}

bool TreeModel::removeRows(int position, int rows, const QModelIndex &parent)
{
	TreeItem *parentItem = get(parent);
	beginRemoveRows(parent, position, position + rows - 1);
	bool result = parentItem->remove(position, rows);
	endRemoveRows();

	return result;
}
/***************************************************************************************************/

/***************************************************************************************************
 * helper functions
 ***************************************************************************************************/
TreeItem* TreeModel::get(const QModelIndex &index) const
{
	if (index.isValid()) {
		TreeItem *item = static_cast<TreeItem*>(index.internalPointer());
		if (item) return item;
	}

	return root;
}

QModelIndex TreeModel::indexOf(TreeItem *item) const
{
	if (item == root || item == NULL)
		return QModelIndex();
	
	Node *parent = item->getParent();
	QList<Node *> parents;
	while (parent && parent != root)
	{
		parents.append(parent);
		parent = parent->getParent();
	}
	
	// default constructor gives root, and root is not in our list
	QModelIndex currIdx;
	parent = root;
	for (QList<Node *>::iterator it = parents.begin(); it != parents.end(); ++it)
		currIdx = index((*it)->childNumber(), 0, currIdx);
	
	// now we have the currIdx of item's direct parent
	currIdx = index(item->childNumber(), 0, currIdx);
	
	return currIdx;
}

TreeItem* TreeModel::addItem(const TypeGroup *senderGroup, const QModelIndex &index)
{
    Node *parentItem = dynamic_cast<Node *>(get(index));
    if (!parentItem) return NULL;
    
    QMap<QString, QVariant> data;
    data["parentID"] = parentItem->id();
    if (!index.isValid())
    	data["ID"] = "root";
    else
        data["ID"] = data["parentID"].toString() + QString::number((unsigned int)parentItem->count() + 1);

    TreeItem *newItem = NULL;
    if (senderGroup->isAction())
        newItem = new Action(data, parentItem);
    else if (senderGroup->isCheck())
        newItem = new Check(data, parentItem);
    else if (senderGroup->isComposite())
        newItem = new Composite(data, parentItem);
    else if (senderGroup->isNode())
        newItem = new Node(data, parentItem);
    else if (senderGroup->isLeaf())
        newItem = new Leaf(data, parentItem);
    else
        return NULL;

	if (addItem(newItem, parentItem, index)) return newItem;
	
	delete newItem;
	return NULL;
}

bool TreeModel::addItem(TreeItem *item)
{
	if (!item) return false;
	
	Node *parentItem = item->getParent();
	if (!parentItem) return false;
	
	QModelIndex pIdx = indexOf(parentItem);
	
	return addItem(item, parentItem, pIdx);
}

bool TreeModel::addItem(TreeItem *item, Node *parentItem, const QModelIndex& pIdx)
{
	beginInsertRows(pIdx, 0, 0);
	bool result = parentItem->insert(item, parentItem->count());
	endInsertRows();
	
	setData(index(item->childNumber(), 0, pIdx), item->name(), Qt::DisplayRole);
	setData(index(item->childNumber(), 1, pIdx), item->id(),  Qt::EditRole);
	
	return result;
}

TreeItem* TreeModel::createItem(const QMap<QString, QVariant>& data, Node* parent)
{
	if (!parent) parent = root ? root : (root = new Node());
	
	QString itemName = data["Name"].toString();
	
	if (itemName.startsWith("Selector") || itemName.startsWith("Sequence"))
		return new Composite(data, parent);
	
	if (itemName.startsWith("Node"))
		return new Node(data, parent);

	if (isDecisionTree())
		return new Leaf(data, parent);
	
	return new Action(data, parent);
}

void TreeModel::removeItem(const QModelIndex& idx)
{
	TreeItem *child = get(idx);
	if (!child) return;
	
	QModelIndex pIdx = indexOf(child->getParent());
	
	removeRows(child->childNumber(), 1, pIdx);
}

/***************************************************************************************************/
