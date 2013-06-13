#pragma once

#include <glload/gl_3_2.h>
#include <glm/glm.hpp>
#include <string>
#include "Texture.h"

enum MeshBuffer {
	VERTEX_BUFFER, COLOUR_BUFFER, TEXTURE_BUFFER, INDEX_BUFFER, MAX_BUFFER
};

namespace gfx {

class Mesh {
public:
	Mesh(void);
	~Mesh(void);

	virtual void Draw();

	static Mesh* GenerateTriangle();
	static Mesh* GenerateSquare();
	static Mesh* GenerateCrosshair();

	static Mesh* CreateSquare(glm::vec3 origin, float size);

	void		SetTexture(Texture* tex)	{ texture = tex; }
	Texture*	GetTexture()				{ return texture; }
	GLuint		GetTextureID()				{ return texture->ID(); }

	void		ModifyTextureCoords(glm::vec2 texCoords[]);

	void		LoadTexture(std::string filename);

protected:
	void BufferData();

	//TODO : add support for DX11 

	GLuint arrayObject;
	GLuint bufferObject[MAX_BUFFER];
	GLuint numVertices;
	GLuint numIndices;
	GLuint type;

	Texture* texture;
	glm::vec2* textureCoords;

	//int* vertices;
	glm::vec3* vertices;
	glm::vec4* colours;
	GLuint* indices;
};

};