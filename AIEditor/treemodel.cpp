#include <QtGui>

#include "treeitem.h"
#include "treemodel.h"

TreeModel::TreeModel(QObject *parent) : QAbstractItemModel(parent)
{
	QMap<QString, QVariant> data;
	data.insert(QString("Name"), QVariant("Name"));
	data.insert(QString("Type"), QVariant("Type"));
	data.insert(QString("Parameters"), QVariant("Parameters"));

	root = new TreeItem(data);
}

TreeModel::~TreeModel()
{
	if (root != NULL)
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

	TreeItem *parentItem = get(parent);
	TreeItem *childItem = parentItem->get(row);

	if (childItem) return createIndex(row, column, childItem);

	return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
	if (!index.isValid())
		return QModelIndex();

	TreeItem *childItem = get(index);
	TreeItem *parentItem = childItem->getParent();

	if (parentItem == root) return QModelIndex();

	return createIndex(parentItem->childNumber(), 0, parentItem);
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
	TreeItem *parentItem = get(parent);

	if (parentItem) return parentItem->count();
	else return 0;
}

int TreeModel::columnCount(const QModelIndex &/*parent*/) const
{
	return 3; // always the same: Name, Type, Parameters (TODO: could possibly extend parameters to have a variable column count)
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
	if (role != Qt::EditRole) return false;

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
	return false; // TODO: allow column removeal ( comes with variable parameter headers)
}

bool TreeModel::insertRows(int position, int rows, const QModelIndex &parent)
{
	TreeItem *parentItem = get(parent);

	bool result;

	beginInsertRows(parent, position, position + rows - 1);
	if (!parentItem) { // then this is root
		if (!root) root = new TreeItem();
	} else result = parentItem->insert(position, rows);
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
/***************************************************************************************************/
