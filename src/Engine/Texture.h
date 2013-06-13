#pragma once

#define TEXTURE_DIRECTORY "../res/textures/"

#include <string>
#include <memory>
#include <iostream>

#include <glload/gl_all.h>
#include <glload/gll.hpp>
#include <glimg/glimg.h>
#include <glimg/TextureGeneratorExceptions.h>

namespace gfx {

class Texture {
public:
	Texture(void);
	Texture(std::string filename);
	~Texture(void);

	GLuint ID() { return textureID; }

	void ToggleFiltering();
	void ToggleRepeating();

private:
	GLuint textureID;
	int LoadFromFile(std::string filename);

	bool filtering;
	bool repeating;
};

};