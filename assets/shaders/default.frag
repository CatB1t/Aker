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
	vec3 result = vec3(0.0f);
	vec3 norma = normalize(vNormal);

	float ambientStrength = 0.1f;
	result = light.color * 0.1f;

	vec3 lightDir = normalize(light.position - vPosition.xyz);
	float diffuseStrength = max(0, dot(lightDir, norma));
	result = result + light.color * diffuseStrength * 0.6;

	vec3 viewDir = normalize(cameraPosition - vPosition.xyz);
	vec3 reflectDir = reflect(-lightDir, norma);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 16);
	result = result + light.color * spec * 0.5f;

	return result;
}

void main () 
{
	vec3 light = calculateLight();
	FragColor = vec4(materialColor * light, 1.0f);
}