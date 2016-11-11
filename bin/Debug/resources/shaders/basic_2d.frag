#version 330 core

layout (location = 0) out vec4 color;

in DATA
{
	vec4 position;
	vec4 color;
	vec2 uv;
	float tid;
    vec2 maskUv;
} fs_in;

uniform vec2 light_pos;
uniform sampler2D textures[31];
uniform sampler2D maskTexture;

void main()
{
	float intensity = 1.0 / length(fs_in.position.xy - light_pos);
	vec4 texColor = fs_in.color;
	if(fs_in.tid > 0) {
	    texColor = texture(textures[0], fs_in.uv);
	}
	vec4 maskColor = texture(maskTexture, fs_in.maskUv);
	color = texColor * maskColor * intensity;
}