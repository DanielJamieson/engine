#version 330

// Vertex shader with texCoords & normals
// based on lighthouse3d example

// Define positions. These are bound explicitly in ModelState.cpp
//  so we don't use layout (location = 0)
layout (location = 0) in vec4 position;
layout (location = 1) in vec4 normal;
layout (location = 2) in vec2 texCoord;

//out vec4 vertexPos;
out vec2 texCoord_frag;
out vec3 normal_frag;

uniform mat4 projMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

void main()
{
	texCoord_frag = texCoord;
	normal_frag = normalize(vec3(viewMatrix * modelMatrix * normal));
	gl_Position = projMatrix * viewMatrix * modelMatrix * position;
}