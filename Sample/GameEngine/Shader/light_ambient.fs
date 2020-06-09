#version 330 core

uniform sampler2D texSampler0;

uniform vec4 lightAmbient;

in vec2 fragmentUV;

out vec4 color;

void main()
{
	vec4 c0 = texture(texSampler0, fragmentUV);
	vec3 c1 = vec3(lightAmbient);
	vec3 c2 = min(c0.rgb * c1, vec3(1, 0));
	color = vec4(c2.rgb, c0.a);
	
}