#pragma once
//#include "Matrix4.h"
//#include "Vector3.h"
//#include "Vector4.h"
//#include "Mesh.h"
#include <vector>

#include "Mesh.h"
#include "Transform.h"

namespace gfx {

class SceneNode {
public:
	SceneNode(void);
	SceneNode(Mesh* mesh);
	SceneNode(Mesh* mesh, glm::vec4 colour);
	~SceneNode(void);

	//void				SetTransform(const glm::mat4 &matrix) { transform = matrix;}
	//const glm::mat4		&GetTransform() const { return transform;}
	//glm::mat4			GetWorldTransform() const { return worldTransform;}

	//glm::vec4			GetColour() const {return colour;}
	//void				SetColour(glm::vec4 c) { colour = c;}

	//glm::vec3			GetModelScale() const {return modelScale;}
	//void				SetModelScale(glm::vec3 s) { modelScale = s;}

	Mesh*				GetMesh()									{ return mesh; }
	glm::mat4			GetModelMatrix()							{ return transform.GetModelMatrix(); }

	void				Scale(glm::vec3 scale_by)					{ transform.Scale(scale_by); }
	void				Rotate(float angle, glm::vec3 axis)			{ transform.Rotate(angle, axis); }
	void				Translate(glm::vec3 offset)					{ transform.Translate(offset); }

	void				ResetAndScale(glm::vec3 scale_by)			{ transform.ResetAndScale(scale_by); }
	void				ResetAndRotate(float angle, glm::vec3 axis) { transform.ResetAndRotate(angle, axis); }
	void				ResetAndTranslate(glm::vec3 offset)			{ transform.ResetAndTranslate(offset); }

	//void				SetMesh(Mesh *m) { mesh = m;}

	void				AddChild(SceneNode *s);

	void				Update(float msec);
	void				Draw();

	std::vector<SceneNode*>::const_iterator		GetChildIteratorStart() { return children.begin(); }
	std::vector<SceneNode*>::const_iterator		GetChildIteratorEnd() { return children.end(); }

protected:

	SceneNode*					parent;
	Mesh*						mesh;
	Transform					transform;

	glm::mat4					worldTransform;
	glm::vec4					colour;

	std::vector<SceneNode*>		children;
};

};