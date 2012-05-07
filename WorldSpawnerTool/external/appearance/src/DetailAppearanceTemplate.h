/*
 * DetailAppearanceTemplate.h
 *
 *  Created on: 10/12/2010
 *      Author: victor
 */

#ifndef DETAILAPPEARANCETEMPLATE_H_
#define DETAILAPPEARANCETEMPLATE_H_

#include "engine/engine.h"
#include "AppearanceTemplate.h"

class DetailAppearanceTemplate : public AppearanceTemplate {
	Vector<String> meshes;

public:
	DetailAppearanceTemplate() {
//		firstMesh = NULL;
	}

	~DetailAppearanceTemplate() {
	}

	void readObject(IffStream* templateData) {
		parse(templateData);
	}

	void parse(IffStream* iffStream);

};

#endif /* DETAILAPPEARANCETEMPLATE_H_ */
