#include "treeitem.h"
#include "composite.h"

TreeItem::TreeItem(Composite *parent)
{
	this->parent = parent;
	data.insert(QString("Name"), QVariant("[No Data]"));
	data.insert(QString("Type"), QVariant("[No Data]"));
	data.insert(QString("Parameters"), QVariant("[No Data]"));
}

TreeItem::TreeItem(const QMap<QString, QVariant> &data, Composite *parent)
{
	this->parent = parent;
	this->data = data;
}

TreeItem::~TreeItem()
{
}

int TreeItem::childNumber()
{
    if (parent) return parent->getIndex(this);

    return 0;
}
