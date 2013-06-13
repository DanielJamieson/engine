#include "HeightMap.h"

using namespace gfx;

HeightMap::HeightMap(std::string filename) {
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

	std::ifstream file((HEIGHTMAP_FILE_DIR + filename).c_str(), std::ios::binary);
	if (!file) {
		return;
	}
	numVertices = RAW_WIDTH * RAW_HEIGHT;
	numIndices = (RAW_WIDTH-1) * (RAW_HEIGHT-1) * 6;
	vertices		= new glm::vec3[numVertices];
	textureCoords	= new glm::vec2[numVertices];
	indices			= new GLuint[numIndices];

	unsigned char* data = new unsigned char[numVertices];
	file.read((char*) data, numVertices*sizeof(unsigned char));
	file.close();

	for (int x = 0; x < RAW_WIDTH; ++x) {
		for (int z = 0; z < RAW_HEIGHT; ++z) {
			int offset = (x * RAW_WIDTH) + z;

			vertices[offset] = glm::vec3( x * HEIGHTMAP_X,
										  data[offset] * HEIGHTMAP_Y,
										  z * HEIGHTMAP_Z);
			//std::cout << "x: " << x * HEIGHTMAP_X <<
			//		   ", y: " << data[offset] * HEIGHTMAP_Y <<
			//		   ", z: " << z * HEIGHTMAP_Z << std::endl;

			textureCoords[offset] = glm::vec2( x * HEIGHTMAP_TEX_X,
											   z * HEIGHTMAP_TEX_Z);
		}
	}

	delete data;
	numIndices = 0;

	for(int x = 0; x < RAW_WIDTH -1; ++ x ) {
		for(int z = 0; z < RAW_HEIGHT -1; ++ z ) {
			GLuint a = ( x * ( RAW_WIDTH )) + z ;
			GLuint b = (( x +1) * ( RAW_WIDTH )) + z ;
			GLuint c = (( x +1) * ( RAW_WIDTH )) + ( z +1);
			GLuint d = ( x * ( RAW_WIDTH )) + ( z +1);
			indices [ numIndices ++] = c;
			indices [ numIndices ++] = b;
			indices [ numIndices ++] = a;
			indices [ numIndices ++] = a;
			indices [ numIndices ++] = d;
			indices [ numIndices ++] = c;
		}
	}

	BufferData();
	LoadTexture("landscape.jpg");
}

HeightMap::~HeightMap(void) {
	glDeleteVertexArrays(1, &arrayObject);
	glDeleteBuffers(MAX_BUFFER, bufferObject);
	delete texture;
	delete[] vertices;
	delete[] colours;
	delete[] textureCoords; 
}