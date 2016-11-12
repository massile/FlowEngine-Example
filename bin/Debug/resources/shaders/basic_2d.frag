#version 330 core

layout (location = 0) out vec4 color;

in DATA
{
	vec4 position;
	vec4 color;
	vec2 uv;
	float tid;
    vec2 maskUv;
	float mid;
} fs_in;

uniform vec2 light_pos;
uniform sampler2D textures[32];

void main()
{
	float intensity = 1.0 / length(fs_in.position.xy - light_pos);
	vec4 texColor = fs_in.color;
	vec4 maskColor = vec4(1.0f);
	if(fs_in.tid > 0) {
	    texColor = texture(textures[0], fs_in.uv);
	}
	if(fs_in.mid > 0) {
	    maskColor = texture(textures[1], fs_in.maskUv);
	}
	color = texColor * maskColor * intensity;
}