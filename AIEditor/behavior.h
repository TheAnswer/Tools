/*
 * This is the base behavior class.
 * For now, it only needs to store an id string, a class name string (selectable),
 * a parent id string, and a type enum (selectable).
 *
 * TODO: add logic abstractions to this class
 */

#ifndef BEHAVIOR_H
#define BEHAVIOR_H

#include <qglobal.h>
#include <QList>
#include <QMap>
#include <QVariant>
#include <QString>
#include <QAction>

#include "treeitem.h"


class Behavior : public TreeItem
{
public:
    Behavior(Composite *parent = 0);
    Behavior(const QMap<QString, QVariant>& data, Composite *parent = 0);
    virtual ~Behavior();

	QAction *getAction() const;
	void setAction(QAction *value);

	QString getId() const;
	void setId(const QString &value);

	QString getClassName() const;
	void setClassName(const QString &value);

	QString getParentId() const;
	void setParentId(const QString &value);

	quint8 getType() const;
	void setType(const quint8 &value);

private:
	QAction *action;
	QString id;
	QString className;
	QString parentId;
    quint8 type;
};

#endif // BEHAVIOR_H
