#version 330 core

layout (location = 0) in vec3 position;

uniform mat4 model;
uniform mat4 pv;

void main ()
{
	gl_Position = pv * model * vec4(position.xyz, 1.0f);
}