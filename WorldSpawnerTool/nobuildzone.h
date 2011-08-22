/*
 * nobuildzone.h
 *
 *  Created on: 02/07/2010
 *      Author: TheAnswer
 */

#ifndef NOBUILDZONE_H_
#define NOBUILDZONE_H_

#include "region.h"

class NoBuildZone : public Region {
public:
	NoBuildZone(qreal radius);
};

#endif /* NOBUILDZONE_H_ */
