#pragma once

#include "Interfaces/Entity.h"
#include "Mesh.h"

namespace game {

class Crosshair : public engine::Entity {
public:
	Crosshair(void);
	~Crosshair(void);

	virtual void update(float msec);
};

};