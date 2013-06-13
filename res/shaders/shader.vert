#version 330

layout (location = 0) in vec4 position;

uniform mat4 projMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

void main()
{
	gl_Position = projMatrix * viewMatrix * modelMatrix * position;	// ORDER IS IMPORTANT!
}
