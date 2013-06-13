#include "Crosshair.h"

using namespace game;

Crosshair::Crosshair(void) {
	gfx::Mesh *m;
	m = gfx::Mesh::GenerateSquare();
	m->LoadTexture("crosshair.png");
	m->GetTexture()->ToggleFiltering();
	node = new gfx::SceneNode(m);
	node->Scale(glm::vec3(0.12, 0.12, 1.0));
}

Crosshair::~Crosshair(void) {
}

void Crosshair::update(float msec) {
}