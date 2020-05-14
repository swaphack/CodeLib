#version 330 core

in vec2 fragmentUV;
in vec4 fragmentColor;

out vec4 color;

uniform sampler2D texSampler0;
uniform sampler2D texSampler1;

void main(){

    // Output color = color of the texture at the specified UV
	vec4 c1 = fragmentColor * texture(texSampler0, fragmentUV);
	vec4 c2 = fragmentColor * texture(texSampler1, fragmentUV);

	color = mix(c1, c2, 0.5f);
}