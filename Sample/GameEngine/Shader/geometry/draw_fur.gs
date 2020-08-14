#version 330 core

uniform int furLayers = 30;
uniform float furDepth = 5.0;

layout (lines) in;
layout (line_strip, max_vertices=120) out;

void main()
{
	int i, layer;

	float delta = 0.1;
	float d = 0.0;

	for	(layer = 0; layer < furLayers; layer++)
	{
		for	(i = 0; i < gl_in.length(); i++)
		{
			vec4 pos = gl_in[i].gl_Position;
			float value = (1 - d) * d;
			pos = pos + vec4 (value, value, value, 0.0);
			gl_Position = pos;

			EmitVertex();
		}
		d+=delta;

		EndPrimitive();
	}
}