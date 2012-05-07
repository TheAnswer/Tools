/*
 * PortalLayout.h
 *
 *  Created on: 02/12/2010
 *      Author: victor
 */

#ifndef PORTALLAYOUT_H_
#define PORTALLAYOUT_H_

#include "IffTemplate.h"

class MeshAppearanceTemplate;
class PathNode;
class FloorMesh;
class PathGraph;

class PortalLayout : public IffTemplate, public Logger {
	int cellTotalNumber;
	//Vector<FloorMesh*> floorMeshes; // indexed by cells started by 0
	Vector<String> floorMeshes;
	Vector<String> appearanceTemplates;
	//Vector<MeshAppearanceTemplate*> appearanceTemplates;
	PathGraph* pathGraph;

public:
	PortalLayout();
	~PortalLayout();

	void readObject(IffStream* templateData) {
		parse(templateData);
	}

	void parse(IffStream* iffStream);

	void parseCELSForm(IffStream* iffStream);

	//void connectFloorMeshGraphs();

	int getFloorMeshID(int globalNodeID, int floorMeshToExclude);

	Vector<PathNode*>* getPath(PathNode* node1, PathNode* node2);

	inline int getCellTotalNumber() {
		return cellTotalNumber;
	}

	inline int getFloorMeshNumber() {
		return floorMeshes.size();
	}

	inline String getFloorMesh(int index) {
		return floorMeshes.get(index);
	}
	
	inline PathGraph* getPathGraph() {
		return pathGraph;
	}


/*	inline FloorMesh* getFloorMesh(int cellIndex) {
		return floorMeshes.get(cellIndex);
	}

	inline MeshAppearanceTemplate* getMeshAppearanceTemplate(int cellIndex) {
		return appearanceTemplates.get(cellIndex);
	}

	inline int getAppearanceTemplatesSize() {
		return appearanceTemplates.size();
	}*/

};

#endif /* PORTALLAYOUT_H_ */
