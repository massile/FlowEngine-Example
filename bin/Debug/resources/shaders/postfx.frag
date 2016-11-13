#version 330 core

layout (location = 0) out vec4 color;
uniform sampler2D tex;

in DATA {
    vec2 uv;
} fs_in;

void main()
{
    vec4 text = texture(tex, fs_in.uv);
    vec3 greyValue = vec3((text.r + text.g + text.b)/3);
	color = vec4(greyValue, 1.0);
}