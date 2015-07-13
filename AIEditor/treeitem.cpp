#include "treeitem.h"

TreeItem::TreeItem(TreeItem *parent)
{
	this->parent = parent;
	data.insert(QString("Name"), QVariant("[No Data]"));
	data.insert(QString("Type"), QVariant("[No Data]"));
	data.insert(QString("Parameters"), QVariant("[No Data]"));
}

TreeItem::TreeItem(const QMap<QString, QVariant> &data, TreeItem *parent)
{
	this->parent = parent;
	this->data = data;
}

TreeItem::~TreeItem()
{
	qDeleteAll(this->children);
}

int TreeItem::childNumber() const
{
    if (parent) return parent->children.indexOf(const_cast<TreeItem*>(this));

    return 0;
}
