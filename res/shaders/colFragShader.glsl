#version 330

smooth in vec4 fragColour;

out vec4 outputColour;

void main()
{
	outputColour = fragColour;
}