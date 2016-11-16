#version 330 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv;

uniform mat4 pr_matrix;
uniform mat4 vw_matrix = mat4(1.0);
uniform mat4 ml_matrix = mat4(1.0);

out DATA
{
	vec4 position;
	vec3 normal;
	vec2 uv;
} vs_out;

void main()
{
    mat4 MVP = pr_matrix * vw_matrix * ml_matrix;
	gl_Position = MVP * position;
}