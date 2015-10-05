/*
 * This is the base behavior class.
 * For now, it only needs to store an id string, a class name string (selectable),
 * a parent id string, and a type enum (selectable).
 *
 * TODO: add logic abstractions to this class
 */

#ifndef BEHAVIOR_H
#define BEHAVIOR_H

#include "treetype.h"


class Behavior : public TreeType
{
public:
    Behavior() : TreeType() {}
    virtual ~Behavior() {}

    bool isBehavior() const { return true; }

    /*
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
    */

private:
    /*
	QAction *action;
	QString id;
	QString className;
	QString parentId;
    quint8 type;
    */
};

#endif // BEHAVIOR_H
