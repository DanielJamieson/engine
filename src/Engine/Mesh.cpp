#include "Mesh.h"

using namespace gfx;

Mesh::Mesh(void)
{
	for(int i = 0; i < MAX_BUFFER; ++ i) {
		bufferObject [i] = 0;
	}
	glGenVertexArrays(1 , &arrayObject);
	numVertices		= 0;
	numIndices		= 0;
	texture			= NULL;
	textureCoords	= NULL;
	vertices		= NULL;
	colours			= NULL;
	indices			= NULL;
	type			= GL_TRIANGLES;
}


Mesh::~Mesh(void)
{
	glDeleteVertexArrays(1, &arrayObject);
	glDeleteBuffers(MAX_BUFFER, bufferObject);
	delete texture;
	delete[] vertices;
	delete[] colours;
	delete[] textureCoords; 
}

Mesh* Mesh::GenerateTriangle() {
	Mesh* m = new Mesh();
	m->numVertices = 3;
	
	m->vertices = new glm::vec3[m->numVertices];
	m->vertices[0] = glm::vec3(0.0f,   0.5f, -2.0f);
	m->vertices[1] = glm::vec3(0.5f,  -0.5f, -2.0f);
	m->vertices[2] = glm::vec3(-0.5f, -0.5f, -2.0f);

	m->textureCoords = new glm::vec2[m->numVertices];
	m->textureCoords[0] = glm::vec2(0.5f, 1.0f);
	m->textureCoords[1] = glm::vec2(1.0f, 0.0f);
	m->textureCoords[2] = glm::vec2(0.0f, 0.0f);

	m->colours = new glm::vec4[m->numVertices];
	m->colours[0] = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
	m->colours[1] = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
	m->colours[2] = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);

	m->BufferData();
	m->LoadTexture("background.jpg");
	return m;
}

Mesh* Mesh::GenerateSquare() {
	Mesh* m = new Mesh();
	m->numVertices = 4;
	m->numIndices = 6;
	
	m->vertices = new glm::vec3[m->numVertices];
	m->vertices[0] = glm::vec3(0.5f,   0.5f, -2.0f);
	m->vertices[1] = glm::vec3(0.5f,  -0.5f, -2.0f);
	m->vertices[2] = glm::vec3(-0.5f, -0.5f, -2.0f);
	m->vertices[3] = glm::vec3(-0.5f,  0.5f, -2.0f);

	m->textureCoords = new glm::vec2[m->numVertices];
	m->textureCoords[0] = glm::vec2(1.0f, 1.0f);
	m->textureCoords[1] = glm::vec2(1.0f, 0.0f);
	m->textureCoords[2] = glm::vec2(0.0f, 0.0f);
	m->textureCoords[3] = glm::vec2(0.0f, 1.0f);

	m->colours = new glm::vec4[m->numVertices];
	m->colours[0] = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
	m->colours[1] = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
	m->colours[2] = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
	m->colours[3] = glm::vec4(0.5f, 0.0f, 0.5f, 1.0f);

	m->indices = new GLuint[m->numIndices];
	m->indices[0] = 0;
	m->indices[1] = 1;
	m->indices[2] = 2;
	m->indices[3] = 2;
	m->indices[4] = 3;
	m->indices[5] = 0;

	m->BufferData();
	m->LoadTexture("background.jpg");
	return m;
}

Mesh* Mesh::GenerateCrosshair() {
	Mesh* m = new Mesh();
	m->numVertices = 4;
	m->numIndices = 6;
	
	m->vertices = new glm::vec3[m->numVertices];
	m->vertices[0] = glm::vec3(0.1f,   0.1f, -2.0f);
	m->vertices[1] = glm::vec3(0.1f,  -0.1f, -2.0f);
	m->vertices[2] = glm::vec3(-0.1f, -0.1f, -2.0f);
	m->vertices[3] = glm::vec3(-0.1f,  0.1f, -2.0f);

	m->textureCoords = new glm::vec2[m->numVertices];
	m->textureCoords[0] = glm::vec2(1.0f, 1.0f);
	m->textureCoords[1] = glm::vec2(1.0f, 0.0f);
	m->textureCoords[2] = glm::vec2(0.0f, 0.0f);
	m->textureCoords[3] = glm::vec2(0.0f, 1.0f);

	m->colours = new glm::vec4[m->numVertices];
	m->colours[0] = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
	m->colours[1] = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
	m->colours[2] = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
	m->colours[3] = glm::vec4(0.5f, 0.0f, 0.5f, 1.0f);

	m->indices = new GLuint[m->numIndices];
	m->indices[0] = 0;
	m->indices[1] = 1;
	m->indices[2] = 2;
	m->indices[3] = 2;
	m->indices[4] = 3;
	m->indices[5] = 0;

	m->BufferData();
	return m;
}

Mesh* Mesh::CreateSquare(glm::vec3 origin, float size) {
	Mesh* m = new Mesh();
	m->numVertices = 4;
	m->numIndices = 6;
	
	m->vertices = new glm::vec3[m->numVertices];
	m->vertices[0] = glm::vec3(origin.x + size, origin.y + size, origin.z);
	m->vertices[1] = glm::vec3(origin.x + size, origin.y,		 origin.z);
	m->vertices[2] = glm::vec3(origin.x,        origin.y,		 origin.z);
	m->vertices[3] = glm::vec3(origin.x,        origin.y + size, origin.z);

	m->textureCoords = new glm::vec2[m->numVertices];
	m->textureCoords[0] = glm::vec2(1.0f, 1.0f);
	m->textureCoords[1] = glm::vec2(1.0f, 0.0f);
	m->textureCoords[2] = glm::vec2(0.0f, 0.0f);
	m->textureCoords[3] = glm::vec2(0.0f, 1.0f);

	m->colours = new glm::vec4[m->numVertices];
	m->colours[0] = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
	m->colours[1] = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
	m->colours[2] = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
	m->colours[3] = glm::vec4(0.5f, 0.0f, 0.5f, 1.0f);

	m->indices = new GLuint[m->numIndices];
	m->indices[0] = 0;
	m->indices[1] = 1;
	m->indices[2] = 2;
	m->indices[3] = 2;
	m->indices[4] = 3;
	m->indices[5] = 0;

	m->BufferData();
	return m;
}

void Mesh::BufferData() 
{
	glBindVertexArray(arrayObject);
	glGenBuffers(1, &bufferObject[VERTEX_BUFFER]);
	glBindBuffer(GL_ARRAY_BUFFER, bufferObject[VERTEX_BUFFER]);
	glBufferData(GL_ARRAY_BUFFER, numVertices*sizeof(glm::vec3),
					vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(VERTEX_BUFFER, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(VERTEX_BUFFER);
	if (textureCoords) {
		glGenBuffers(1, &bufferObject[TEXTURE_BUFFER]);
		glBindBuffer(GL_ARRAY_BUFFER, bufferObject[TEXTURE_BUFFER]);
		glBufferData(GL_ARRAY_BUFFER, numVertices*sizeof(glm::vec2), 
					textureCoords, GL_DYNAMIC_DRAW);
		glVertexAttribPointer(TEXTURE_BUFFER, 2, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(TEXTURE_BUFFER);
	}
	if (colours)	{ // in case we don't have colours for this mesh {
		glGenBuffers(1, &bufferObject[COLOUR_BUFFER]);
		glBindBuffer(GL_ARRAY_BUFFER, bufferObject[COLOUR_BUFFER]);
		glBufferData(GL_ARRAY_BUFFER, numVertices*sizeof(glm::vec4),
						colours, GL_STATIC_DRAW);
		glVertexAttribPointer(COLOUR_BUFFER, 4, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(COLOUR_BUFFER);
	}
	if (indices)	{ // in case we don't have indices for this mesh {
		std::cout << "buffered indices" << std::endl;
		glGenBuffers(1, &bufferObject[INDEX_BUFFER]);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferObject[INDEX_BUFFER]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices*sizeof(GLuint),
						indices, GL_STATIC_DRAW);
	}
	glBindVertexArray(0);
}

void Mesh::Draw() {
	if (texture != NULL) glBindTexture(GL_TEXTURE_2D, texture->ID());

	glBindVertexArray(arrayObject);
	if (indices) {
		glDrawElements(type, numIndices, GL_UNSIGNED_INT, 0);
		//std::cout << "rendering indices" << std::endl;
	} else
		glDrawArrays(type, 0, numVertices);
	
	glBindVertexArray(0);
	glBindTexture ( GL_TEXTURE_2D , 0);
}

void Mesh::LoadTexture(std::string filename) {
	texture = new Texture(filename);
}

void Mesh::ModifyTextureCoords(glm::vec2 texCoords[]) {
	textureCoords = texCoords;
	this->BufferData();
}