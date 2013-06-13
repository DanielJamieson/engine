#version 330

// Fragment Shader w/ Lighting
// Based on lighthouse3d example

layout (std140) uniform Material {
	vec4 diffuse;
	vec4 ambient;
	vec4 specular;
	vec4 emissive;
	float shininess;
	int texCount;
};

in vec3 normal_frag;
in vec2 texCoord_frag;

out vec4 output;

uniform sampler2D texUnit;

void main()
{
	vec4 color;
	vec4 amb;
	float intensity;
	vec3 lightDir;
	vec3 n;
	
	lightDir = normalize(vec3(1.0,1.0,1.0));
	n = normalize(normal_frag);
	intensity = max(dot(lightDir,n),0.0);
	
	if (texCount == 0) {
		color = diffuse;
		amb = ambient;
	}
	else {
		// texture2D is deprecated!
		color = texture2D(texUnit, texCoord_frag) * diffuse;
		amb = color * 0.33;
	}
	output = (color * intensity) + amb;

}
