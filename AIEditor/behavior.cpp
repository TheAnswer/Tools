#include "behavior.h"

Behavior::Behavior()
{

}

Behavior::~Behavior()
{

}
QAction *Behavior::getAction() const
{
	return action;
}
void Behavior::setAction(QAction *value)
{
	action = value;
}

QString Behavior::getId() const
{
	return id;
}

void Behavior::setId(const QString &value)
{
	id = value;
}
QString Behavior::getClassName() const
{
	return className;
}

void Behavior::setClassName(const QString &value)
{
	className = value;
}
QString Behavior::getParentId() const
{
	return parentId;
}

void Behavior::setParentId(const QString &value)
{
	parentId = value;
}
quint8 Behavior::getType() const
{
	return type;
}

void Behavior::setType(const quint8 &value)
{
	type = value;
}





