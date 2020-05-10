#version 330 core

in vec2 UV;
in vec4 Color;

out vec4 color;

uniform sampler2D texSampler0;
uniform sampler2D texSampler1;

void main(){

    // Output color = color of the texture at the specified UV
	vec4 c1 = texture(texSampler0, UV);
	vec4 c2 = texture(texSampler1, UV);

	color = mix(c1, c2, 0.5f);
}