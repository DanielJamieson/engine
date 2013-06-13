#pragma once

#define PI_OVER_360 0.00872664625

#include "Renderer.h"

#include <glload/gl_3_2.h>
#include <glload/gll.hpp>
#include <GL/glfw.h>

#include "Shader.h"
#include "SceneNode.h"
#include "Heightmap.h"

using namespace engine;

class OGLRenderer :	public Renderer
{
public:
	virtual void	RenderScene();
	virtual void	UpdateScene(float msec);

	virtual void	SwitchToOrthographic();
	virtual void	SwitchToPerspective();
	
	virtual void	PollScene();

	void			DrawNode(SceneNode *n);
	
	void			SetCamera(engine::Camera *c) { camera = c; }
	void			SetRoot(SceneNode *r) { root = r; }

	//TODO : temporary input system
	void			SetupOpenGLContext();

	void			UpdateShaderMatrices();

	void			UpdateTextureMatrix(float rotation);
	void			SetTextureRepeating(GLuint target, bool repeating);
	void			ToggleFiltering(GLuint target, bool filtering);

	void			SetShader(string name);

	Shader*			GetCurrentShader() { return currentShader; }

	void			AddNodeToSceneGraph(SceneNode *s);

	glm::mat4 PerspectiveMatrix(float znear, float zfar, float aspect, float fov);
	glm::mat4 OrthographicMatrix(float znear, float zfar,float right, float left, float top, float bottom);

	static bool Initialise(Window &window) {
		renderer = new OGLRenderer(window);
		return renderer->HasInitialised();
	}

	static void Destroy() {
		delete renderer;
	}

	bool HasInitialised() { return init; }
	
	//TODO : not sure if needed
	static OGLRenderer& GetRenderer() { return *renderer; }
private:
	static OGLRenderer* renderer;
	bool init;

	Projection currentProjection; 
	
	Shader* currentShader;
	vector<Shader*> shaderList;

	HeightMap* land;

	SceneNode* root;

	OGLRenderer(Window &window);
	virtual ~OGLRenderer(void);
};
