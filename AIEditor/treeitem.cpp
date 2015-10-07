#include "treeitem.h"
#include "composite.h"

TreeItem::TreeItem(Node *parent) : parent(parent)
{
	data["Name"] = "none";
	data["iName"] = "";
	data["fName"] = "";
    data["ID"] = "none";
    data["parentID"] = "";
}

TreeItem::TreeItem(const QMap<QString, QVariant> &data, Node *parent)
    : data(data), parent(parent) {}

TreeItem::~TreeItem()
{
}

int TreeItem::childNumber()
{
    if (parent) return parent->getIndex(this);

    return 0;
}
