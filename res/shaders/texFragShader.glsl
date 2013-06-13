#version 330

uniform sampler2D diffuseTex;

smooth in vec4 fragColour;

in Vertex {
	vec2 texCoord;
} IN;

out vec4 gl_FragColor;

void main()
{
	gl_FragColor = texture(diffuseTex, IN.texCoord);
}