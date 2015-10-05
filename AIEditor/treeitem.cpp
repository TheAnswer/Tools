#include "treeitem.h"
#include "composite.h"

TreeItem::TreeItem(Node *parent)
{
	this->parent = parent;
	data.insert(QString("Name"), QVariant("[No Data]"));
    data.insert(QString("Type"), QVariant("[No Data]"));
}

TreeItem::TreeItem(const QMap<QString, QVariant> &data, Node *parent)
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
