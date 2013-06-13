#include "Shader.h"

using namespace gfx;

Shader::Shader() {
	loadFailed = true;
}

Shader::Shader(string name, string vFile, string fFile, string gFile) {
	this->name = name;
	CreateShader(vFile, fFile, gFile);
	loadFailed = false;
}

void Shader::CreateShader(string vFile, string fFile, string gFile) {
	program		= glCreateProgram();
	objects[SHADER_VERTEX]   =	GenerateShader(vFile, GL_VERTEX_SHADER);
	objects[SHADER_FRAGMENT] =	GenerateShader(fFile, GL_FRAGMENT_SHADER);
	objects[SHADER_GEOMETRY] =	0;

	if (!gFile.empty()) {
		objects[SHADER_GEOMETRY] = GenerateShader(gFile, GL_GEOMETRY_SHADER);

		glAttachShader(program, objects[SHADER_GEOMETRY]);
	}

	glAttachShader(program, objects[SHADER_VERTEX]);
	glAttachShader(program, objects[SHADER_FRAGMENT]);

	SetDefaultAttributes();
}

Shader::~Shader(void) {
	for (int i = 0; i < 3; ++i) {
		glDetachShader(program, objects[i]);
		glDeleteShader(objects[i]);
	}
	glDeleteProgram(program);
}

GLuint Shader::GenerateShader(string from, GLenum type) {
	from = SHADER_DIRECTORY + from;
	cout << "Compiling Shader..." << endl;

	string load;
	if(!LoadShaderFile(from, load)) {
		cout << "Compiling failed!" << endl;
		loadFailed = true;
		return 0;
	}

	GLuint shader = glCreateShader(type);

	const char *chars = load.c_str();
	glShaderSource(shader, 1, &chars, NULL);
	glCompileShader(shader);

	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

	if (status == GL_FALSE) {
		cout << "Compiling failed!" << endl;
		char error[512];
		glGetInfoLogARB(shader, sizeof(error), NULL, error);
		cout << error;
		loadFailed = true;
		return 0;
	}
	cout << "Compiling success!" << endl;
	loadFailed = false;
	return shader;
}

bool Shader::LoadShaderFile(string from, string &into) {
	ifstream	file;
	string		temp;

	cout << "Loading shader text from " << from << endl << endl;

	file.open(from.c_str());
	if (!file.is_open()) {
		cout << "File does not exist!" << endl;
		return false;
	}
	while (!file.eof()) {
		getline(file, temp);
		into += temp + "\n";
	}

	file.close();
	cout << into << endl << endl;
	cout << "Loaded shader text!" << endl << endl;
	return true;
}

void Shader::SetDefaultAttributes() {
	glBindAttribLocation(program, VERTEX_BUFFER, "position");
	glBindAttribLocation(program, COLOUR_BUFFER, "colour");
	glBindAttribLocation(program, TEXTURE_BUFFER, "texCoord");
}

bool Shader::LinkProgram() {
	if (loadFailed) {
		return false;
	}
	glLinkProgram(program);

	GLint code;
	glGetProgramiv(program, GL_LINK_STATUS, &code);
	return code == GL_TRUE ? true : false;
}