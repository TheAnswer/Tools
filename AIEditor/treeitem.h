#ifndef TREEITEM_H
#define TREEITEM_H

#include <QList>
#include <QMap>
#include <QString>
#include <QVariant>

class Node;

class TreeItem
{
public:
    TreeItem(Node *parent = 0);
    TreeItem(const QMap<QString, QVariant> &data, Node *parent = 0);
    virtual ~TreeItem();

    virtual size_t count() const {
        return 0;
	}

    virtual TreeItem* get(const size_t) {
        return NULL;
	}

	QVariant get(const QString &field) const {
		return data.value(field);
	}

    Node* getParent() const {
		return parent;
	}

    bool set(const QString &field, const QVariant &value) {
		QMap<QString, QVariant>::iterator it = data.insert(field, value);

		if (it.value() != value || it.key() != field) return false;

		return true;
	}

    virtual bool insert(TreeItem *, const size_t) {
        return false;
	}

    virtual bool insert(const size_t, const size_t) {
        return false;
	}

    virtual bool remove(const size_t) {
        return false;
	}

    virtual bool remove(const size_t, const size_t) {
        return false;
	}

    int childNumber();

    const QString& id() const { return stringID; }
    const QString& id(const QString& i) { return stringID = i; }

private:
	QMap<QString, QVariant> data;
    Node *parent;
    QString stringID;
};

#endif // TREEITEM_H
