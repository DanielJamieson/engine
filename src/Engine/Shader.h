#pragma once
#include <iostream>
#include <fstream>
#include <glload/gl_3_2.h>
#include <glload/gll.hpp>
#include <GL/glfw.h>
#include "Mesh.h"

#define SHADER_VERTEX 0
#define SHADER_FRAGMENT 1
#define SHADER_GEOMETRY 2
#define SHADER_TESS_CONTROL 3
#define SHADER_TESS_EVAL 4

#define SHADER_DIRECTORY "../res/shaders/"

#define TEXTURE_SHADERS 
#define COLOUR_SHADERS

using namespace std;

namespace gfx {

class Shader
{
public:
	Shader(void);
	Shader(string name, string vertex, string fragment, string geometry = "");
	~Shader(void);
	
	void	CreateShader(string vFile, string fFile, string gFile);
	bool	LinkProgram();

	GLuint	GetProgram() { return program; }
	string	GetName() { return name; }
protected:
	string name;
	void	SetDefaultAttributes();
	bool	LoadShaderFile(std::string from, string & into);
	GLuint	GenerateShader(std::string from, GLenum type);
	
	GLuint	objects[3];
	GLuint	program;

	bool	loadFailed;
};

};