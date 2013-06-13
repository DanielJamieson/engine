#include "Texture.h"

using namespace gfx;

Texture::Texture(void) {
}

Texture::Texture(std::string filename) {
	LoadFromFile(filename);
}

Texture::~Texture(void) {
	glDeleteTextures(1, &textureID);
}

int Texture::LoadFromFile(std::string filename) {
	/* create and fill array with GL texture ids */
	glGenTextures(1, &textureID); /* Texture name generation */
	
	try {
		std::auto_ptr<glimg::ImageSet>
			pImgSet(glimg::loaders::stb::LoadFromFile((TEXTURE_DIRECTORY + filename).c_str()));
		
		textureID = glimg::CreateTexture(pImgSet.get(), 0);
	} catch (glimg::loaders::stb::StbLoaderException &e) {
		//Image file loading failed.
		std::cout << "Failed to load texture: " << TEXTURE_DIRECTORY
				<< filename.c_str() << std::endl;
		return 1;
	}
	catch (glimg::TextureGenerationException &e) {
		//Texture creation failed.
		std::cout << "Failed to create texture: " << TEXTURE_DIRECTORY
			<< filename.c_str() << std::endl;
		return 1;
	}

	std::cout << "Loaded texture: " << TEXTURE_DIRECTORY
			<< filename << " with index " << textureID << std::endl;
	return 0;
}

void Texture::ToggleFiltering() {
	filtering = !filtering;
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filtering ? GL_LINEAR_MIPMAP_LINEAR : GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filtering ? GL_LINEAR_MIPMAP_LINEAR : GL_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::ToggleRepeating() {
	repeating = !repeating;
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, repeating ? GL_REPEAT : GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, repeating ? GL_REPEAT : GL_CLAMP);
	glBindTexture(GL_TEXTURE_2D, 0);
}