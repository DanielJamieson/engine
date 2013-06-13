#version 330

// Vertex shader with texCoords & normals
// based on lighthouse3d example

// Define positions. These are bound explicitly in ModelState.cpp
//  so we don't use layout (location = i)
in vec3 position;
in vec3 normal;
in vec2 texCoord;

out vec2 texCoord_frag;
out vec3 normal_frag;
out vec3 light_pos;

uniform mat4 projMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

void main()
{
	texCoord_frag = texCoord;
	normal_frag = normalize(vec3(viewMatrix * modelMatrix * vec4(normal,0.0)));
	gl_Position = projMatrix * viewMatrix * modelMatrix * vec4(position,1.0);
	
	vec4 tmp = projMatrix * modelMatrix * vec4(1.0,1.0,1.0,1.0);
	light_pos = vec3(tmp.z, tmp.y, tmp.z);
}