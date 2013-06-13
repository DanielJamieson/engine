#include "OGLRenderer.h"

OGLRenderer* OGLRenderer::renderer;

// GLFW CALLS
//Called whenever the window is resized. The new window size is given, in pixels.
//This is an opportunity to call glViewport or glScissor to keep up with the change in size.
Window* globalWindow;
void GLFWCALL reshape (int w, int h)
{
	globalWindow->reshape(w, h);
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
}

Mesh* triangle;
Mesh* square;

SceneNode* sq;

OGLRenderer::OGLRenderer(Window &window)
{
	//this->camera = camera;

	SetupOpenGLContext();
	
	shaderList.push_back(new Shader("TextureShader", "texVertexShader.glsl", "texFragShader.glsl"));
	shaderList.push_back(new Shader("ColourShader",  "colVertexShader.glsl", "colFragShader.glsl"));

	SetShader("TextureShader");

	if (!currentShader->LinkProgram()) {
		return;
	}
	
	//ToggleFiltering(crosshair->GetTextureID(), true);
	//triangle = Mesh::GenerateTriangle();
	//land = new HeightMap("heightmap1.raw");
	//square = Mesh::GenerateSquare();

	root = new SceneNode();
	nodeCount = 0;
}

OGLRenderer::~OGLRenderer(void)
{
	delete triangle;
	delete square;
	for (int i = 0; i < shaderList.size(); ++i) {
		delete shaderList[i];
	}
}

/// OGLRenderer Methods
void OGLRenderer::RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(currentShader->GetProgram());
	UpdateShaderMatrices();

	DrawNode(root);
	
	glUseProgram(0);
	glfwSwapBuffers();
}

void OGLRenderer::DrawNode(SceneNode *n) {
	if (n->GetMesh()) {
		glm::mat4 nodeModelMatrix = n->GetModelMatrix();
		glUniformMatrix4fv(
			glGetUniformLocation(currentShader->GetProgram(),
			"modelMatrix"), 1, GL_FALSE, glm::value_ptr(nodeModelMatrix));
		n->Draw();

		for (std::vector<SceneNode*>::const_iterator
			i = n->GetChildIteratorStart();
			i != n->GetChildIteratorEnd();
			++i) 
		{
				DrawNode(*i);
		}	
	}
}

void OGLRenderer::UpdateScene(float msec)
{
	PollScene();
	camera->update(msec);
	viewMatrix = *camera->getViewMatrix();
}

void OGLRenderer::UpdateShaderMatrices() {
	if(currentShader) {
		glUniformMatrix4fv(
			glGetUniformLocation(currentShader->GetProgram(),
			"modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix));
		glUniformMatrix4fv(
			glGetUniformLocation(currentShader->GetProgram(),
			"viewMatrix"), 1, GL_FALSE, glm::value_ptr(viewMatrix));
		glUniformMatrix4fv(
			glGetUniformLocation(currentShader->GetProgram(),
			"projMatrix"), 1, GL_FALSE, glm::value_ptr(projMatrix));

		glUniform1i(glGetUniformLocation(currentShader->GetProgram(), "diffuseTex"), 0);
	}
}

void OGLRenderer::SetShader(string name) {
	for (int i = 0; i < shaderList.size(); ++i) {
		if (shaderList[i]->GetName() == name) {
			currentShader = shaderList[i];
			return;
		}
	}
	cout << "could not set shader: " << name << std::endl;
}

//TODO : A more complex polling system. currently the latest game entities are simply added as children of the root node, but a more complex system is desirable
void OGLRenderer::PollScene() {
	if (camera == NULL) {
		//camera = currentScene->GetCamera();
	}

	if (nodeCount < currentScene->NodeCount()) {
		std::vector<SceneNode*> tempNodes = currentScene->GetNodes();
		int newNodes = currentScene->NodeCount() - nodeCount;

		for (int i = (tempNodes.size()-newNodes); i < tempNodes.size(); ++i) {
			AddNodeToSceneGraph(tempNodes[i]);
		}
		nodeCount = currentScene->NodeCount();
	}
}

void OGLRenderer::AddNodeToSceneGraph(SceneNode *s) {
	std::cout << "node added to scene graph" << std::endl;
	root->AddChild(s);
}

/*void OGLRenderer::input(float delta) {
	/*if (glfwGetKey('W'))
	{
		camera->forward(delta);
	}
	if (glfwGetKey('A'))
	{
		camera->left(delta);
	}
	if (glfwGetKey('S'))
	{
		camera->backward(delta);
	}
	if (glfwGetKey('D'))
	{
		camera->right(delta);
	}
	if (glfwGetKey('P'))
		SwitchToPerspective();
	if (glfwGetKey('O'))
		SwitchToOrthographic();

	if (glfwGetKey(GLFW_KEY_UP)) {
		root->Scale(glm::vec3(1.1, 1.1, 1.1));
		std::cout << "up" << std::endl;
	}
	if (glfwGetKey(GLFW_KEY_DOWN))
		root->Scale(glm::vec3(0.9, 0.9, 0.9));
}*/

void OGLRenderer::SetupOpenGLContext() {
	if(!glfwInit())
		throw std::runtime_error("Unable to initialise GLFW");
	glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4); // 4x AA
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 3);
	glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef DEBUG
	glfwOpenWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
#endif
	if(!glfwOpenWindow((int) Window::GetWindow().GetWindowSize().x, (int) Window::GetWindow().GetWindowSize().y, 8, 8, 8, 0, 24, 0, GLFW_WINDOW))
	{
		glfwTerminate();
		throw std::runtime_error("Unable to open a GLFW window");
	}
	if(glload::LoadFunctions() == glload::LS_LOAD_FAILED)
	{
		glfwTerminate();
		throw std::runtime_error("GLFW Load failed");
	}
	glfwSetWindowTitle(WINDOW_TITLE);
	glfwSetWindowSizeCallback((GLFWwindowsizefun) reshape);
	glfwSetMousePosCallback((GLFWmouseposfun) Window::GetWindow().GetMouse()->CallbackFunction());
	glfwSetKeyCallback((GLFWkeyfun) Window::GetWindow().GetKeyboard()->CallbackFunction());
	// Enable vSync//glfwSwapInterval(1);
	// 3D environment enables
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	//glFrontFace(GL_CW);
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	this->modelMatrix = glm::mat4(1.0f);
	SwitchToPerspective();
	//SwitchToOrthographic();
}

void OGLRenderer::SwitchToOrthographic() {
	projMatrix = OrthographicMatrix(-1.0f, 10000.0f, Window::GetWindow().GetWindowSize().x/2.0f, -Window::GetWindow().GetWindowSize().y/2.0f, 
									Window::GetWindow().GetWindowSize().y/2.0f, -Window::GetWindow().GetWindowSize().y/2.0f);
	projMatrix = glm::ortho(-Window::GetWindow().GetWindowSize().y/2.0f, Window::GetWindow().GetWindowSize().x/2.0f, -Window::GetWindow().GetWindowSize().y/2.0f,
								Window::GetWindow().GetWindowSize().y/2.0f, 1.0f, 10000.0f);
	currentProjection = ORTHOGRAPHIC;
}

void OGLRenderer::SwitchToPerspective() {
	projMatrix = PerspectiveMatrix(1.0f, 1000.0f, Window::GetWindow().GetWindowSize().x / Window::GetWindow().GetWindowSize().y, 45.0f);
	//projMatrix = glm::mat4(1.0f);
	currentProjection = PERSPECTIVE;
}

void OGLRenderer::UpdateTextureMatrix(float rotation) {

}

void OGLRenderer::SetTextureRepeating(GLuint target, bool repeating) {
	glBindTexture(GL_TEXTURE_2D, target);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, repeating ? GL_REPEAT : GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, repeating ? GL_REPEAT : GL_CLAMP);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void OGLRenderer::ToggleFiltering(GLuint target, bool filtering) {
	glBindTexture(GL_TEXTURE_2D, target);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filtering ? GL_LINEAR_MIPMAP_LINEAR : GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filtering ? GL_LINEAR_MIPMAP_LINEAR : GL_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);
}

glm::mat4 OGLRenderer::PerspectiveMatrix(float znear, float zfar, float aspect, float fov) {
	glm::mat4 m;

	const float h = 1.0f / tan(fov*PI_OVER_360);
	float neg_depth = znear-zfar;

	m[0][0]	= h / aspect;
	m[1][1]	= h;
	m[2][2]	= (zfar + znear)/neg_depth;
	m[2][3]	= -1.0f;
	m[3][2]	= 2.0f*(znear*zfar)/neg_depth;
	m[3][3]	= 0.0f;

	m = glm::perspective(fov, aspect, znear, zfar);

	return m;
}

glm::mat4 OGLRenderer::OrthographicMatrix(float znear, float zfar, float right, float left, float top, float bottom) {
	glm::mat4 m;

	m[0][0]	= 2.0f / (right-left);
	m[1][1]	= 2.0f / (top-bottom);
	m[2][2]	= -2.0f / (zfar-znear);

	m[3][0]  = -(right+left)/(right-left);
	m[3][1]  = -(top+bottom)/(top-bottom);
	m[3][2]  = -(zfar+znear)/(zfar-znear);
	m[3][3]  = 1.0f;

	m = glm::ortho(left, right, bottom, top, znear, zfar);

	return m;
}

//  Calculate the FPS and set it in the title bar
//void OGLRenderer::UpdateFPS() {

	/*if (glfwGetTime() - last_fps > 0.2) {
		sprintf(title_buffer, "%s - %i fps", WIN_TITLE, fps);
		glfwSetWindowTitle(title_buffer);

		fps = 0;
		last_fps += 1.0;
	}
	fps++;	// Increment Frame counter*/
//}

/*void OGLRenderer::init() {

	camera = new engine::Camera(glm::vec3(0, 0, 0), glm::vec3(0.0, 0.0, -1.0));
	// Set up projection matrix
	glm::mat4 projection = glm::perspective(
			37.0f,
			1.0f*window->GetWindowSize().x / window->GetWindowSize().y,
			1.0f,
			1000.0f
	);
	this->projMatrix = &projection;
	glm::mat4 identity = glm::mat4(1.0f);
	this->modelMatrix = &identity;

	//simpleShader	= new Shader(SHADERDIR"TechVertex.glsl", SHADERDIR"TechFragment.glsl");
	//if(!simpleShader->LinkProgram() ){
	//	return;
	//}

	//std::vector<GLuint> shaderList;
	///////////////////////////////////////////////////////////////////////////
	// Load shaders

	//shaderList.push_back(shaders.LoadShader(GL_VERTEX_SHADER, "shaders\\vertexShader.glsl"));
	//shaderList.push_back(shaders.LoadShader(GL_FRAGMENT_SHADER, "shaders\\fragShader.glsl"));

	// Create shader program and add shaders
	//program = shaders.CreateProgram(shaderList);

	// Link the program and detach linked shaders
	//program = shaders.LinkProgram(program, shaderList);
	projUniform = glGetUniformLocation(program, "projMatrix");
	if (projUniform == -1)	fprintf(stderr, "Could not bind uniform: projMatrix\n");
	viewUniform = glGetUniformLocation(program, "viewMatrix");
	if (viewUniform == -1)	fprintf(stderr, "Could not bind uniform: viewMatrix\n");
	modelUniform = glGetUniformLocation(program, "modelMatrix");
	if (modelUniform == -1)	fprintf(stderr, "Could not bind uniform: modelMatrix\n");

	glGenBuffers(1, &pbo); 
	glBindBuffer(GL_ARRAY_BUFFER, pbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW); 
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	std::cout << "OGLRenderer initialised" << std::endl;
}*/