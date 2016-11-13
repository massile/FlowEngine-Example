#version 330 core

layout (location = 0) in vec4 position;
layout (location = 2) in vec2 uv;
uniform mat4 pr_matrix;

out DATA {
    vec2 uv;
} vs_out;

void main()
{
	gl_Position = pr_matrix * position;
	vs_out.uv = uv;
}