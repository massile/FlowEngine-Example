#version 330 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 color;
layout (location = 2) in vec2 uv;
layout (location = 3) in vec2 maskUv;
layout (location = 4) in float tid;
layout (location = 5) in float mid;

uniform mat4 pr_matrix;
uniform mat4 vw_matrix = mat4(1.0);
uniform mat4 ml_matrix = mat4(1.0);

out DATA
{
	vec4 position;
	vec4 color;
	vec2 uv;
	float tid;
	vec2 maskUv;
	float mid;
} vs_out;

void main()
{
    mat4 MVP = pr_matrix * vw_matrix * ml_matrix;
	gl_Position = MVP * position;
	vs_out.position = ml_matrix * position;
    vs_out.color = color;
    vs_out.tid = tid;
    vs_out.mid = mid;
    vs_out.uv= vec2(uv.x, 1-uv.y);
    vs_out.maskUv = (MVP * vec4(maskUv, 0.0, 0.0)).xy;
}