#include "SceneNode.h"

using namespace gfx;

SceneNode::SceneNode()
{
	Mesh *m = new Mesh();
	this->mesh = m;
	this->colour = glm::vec4(1, 1, 1, 1);
	parent = NULL;
	//transform->ResetAndScale(glm::vec3(1, 1, 1));
}

SceneNode::SceneNode(Mesh* mesh)
{
	this->mesh = mesh;
	this->colour = glm::vec4(1, 1, 1, 1);
	parent = NULL;
	//transform->ResetAndScale(glm::vec3(1, 1, 1));
}

SceneNode::SceneNode(Mesh* mesh, glm::vec4 colour)
{
	this->mesh = mesh;
	this->colour = colour;
	parent = NULL;
	//transform->ResetAndScale(glm::vec3(1, 1, 1));
}

SceneNode::~SceneNode(void)
{
	for (unsigned int i = 0; i < children.size(); ++i) {
		delete children[i];
	}
}

void SceneNode::AddChild(SceneNode *s) {
	children.push_back(s);
	s->parent = this;
}

void SceneNode::Update(float msec) {
}

void SceneNode::Draw() {
	if (mesh) mesh->Draw();
}