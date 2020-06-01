#version 330 core

uniform sampler2D texSampler0;
uniform sampler2D texSampler1;

in vec2 fragmentUV;
in vec4 fragmentColor;

out vec4 color;

void main()
{
    // Output color = color of the texture at the specified UV
	vec4 c1 = texture(texSampler0, fragmentUV);
	vec4 c2 = texture(texSampler1, fragmentUV);

	color = fragmentColor * mix(c1, c2, 0.5f);
}