#ifndef TREEITEM_H
#define TREEITEM_H

#include <QList>
#include <QMap>
#include <QString>
#include <QVariant>

class TreeItem
{
public:
	TreeItem(TreeItem *parent = 0);
	TreeItem(const QMap<QString, QVariant> &data, TreeItem *parent = 0);
	~TreeItem();

	int count() const {
		return children.count();
	}

	TreeItem* get(int index) {
		return children.value(index);
	}

	QVariant get(const QString &field) const {
		return data.value(field);
	}

	TreeItem* getParent() {
		return parent;
	}

	bool set(const QString &field, const QVariant &value) {
		QMap<QString, QVariant>::iterator it = data.insert(field, value);

		if (it.value() != value || it.key() != field) return false;

		return true;
	}

	bool insert(TreeItem *newChild, int position = 0) {
		children.insert(position, newChild);

		if (children.at(position) != newChild) return false;

		return true;
	}

	bool insert(int position, int count) {
		if (position < 0 || position > children.size()) return false;

		for (int row = 0; row < count; row++)
			children.insert(position, new TreeItem(this));

		return true;
	}

	bool remove(int position = 0) {
		TreeItem *childItem = children.at(position);

		children.removeAt(position);

		if (children.contains(childItem)) return false;

		return true;
	}

	bool remove(int position, int count) {
		if (position < 0 || position + count > children.size()) return false;

		for (int row = 0; row < count; row++)
			delete children.takeAt(position);

		return true;
	}

	int childNumber() const;

private:
	QList<TreeItem*> children;
	QMap<QString, QVariant> data;
	TreeItem *parent;
};

#endif // TREEITEM_H
