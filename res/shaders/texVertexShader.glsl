#version 330

uniform mat4 projMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

in vec3 vertexPosition;
in vec4 vertexColour;
in vec2 texCoord;

out Vertex {
	vec2 texCoord;
} OUT; 

smooth out vec4 fragColour;

void main(void) {
	mat4 mvp = projMatrix * viewMatrix * modelMatrix;
    gl_Position = mvp * vec4(vertexPosition, 1.0f);
	fragColour = vertexColour;
	OUT.texCoord = texCoord;
}