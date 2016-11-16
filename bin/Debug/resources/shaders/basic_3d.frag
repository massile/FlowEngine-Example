#version 330 core

layout (location = 0) out vec4 color;

in DATA
{
	vec4 position;
	vec3 normal;
	vec2 uv;
} fs_in;


void main()
{
    color = vec4(1, 1, 1, 1);
}