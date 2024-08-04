#version 330 core

out vec4 FragColor;

struct Light
{
	vec3 position;
	vec3 color;
};

in vec4 vPosition;
in vec3 vNormal;

uniform Light light;
uniform vec3 cameraPosition;

vec3 materialColor = vec3(1.0f, 0.0f, 0.0f);

vec3 calculateLight()
{
	vec3 normal = normalize(vNormal);

	float result = 0.0;
	float ambientStrength = 0.1f;

	result += ambientStrength;

	vec3 lightDir = normalize(light.position - vPosition.xyz);
	float diffuseStrength = max(0, dot(lightDir, normal));
	result += diffuseStrength;

	vec3 viewDir = normalize(cameraPosition - vPosition.xyz);
	vec3 reflectDir = reflect(-lightDir, normal);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 16);
	result += spec;

	return light.color * result;
}

void main () 
{
	vec3 light = calculateLight();
	FragColor = vec4(materialColor * light, 1.0f);
}