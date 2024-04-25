#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

out vec4 vPosition;
out vec3 vNormal;

uniform mat4 model;
uniform mat4 pv;

void main ()
{
	vPosition = model * vec4(position.xyz, 1.0f);
	vNormal = mat3(transpose(inverse(model))) * normal;
	gl_Position = pv * model * vec4(position.xyz, 1.0f);
}