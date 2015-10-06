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
    
    QVariant name() const { return data["Name"]; }
    QVariant name(const QString &i) { return data["Name"] = i; }

    QVariant id() const { return data["ID"]; }
    QVariant id(const QString& i) { return data["ID"] = i; }
    
    QVariant parentID() const { return data["parentID"]; }
    QVariant parentID(const QString& i) { return data["parentID"] = i; }

private:
	QMap<QString, QVariant> data;
    Node *parent;
};

#endif // TREEITEM_H
