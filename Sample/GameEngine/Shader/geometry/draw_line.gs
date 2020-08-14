#version 330 core

layout (lines) in;
layout (line_strip, max_vertices=2) out;

void main()
{
	gl_Position = gl_in[0].gl_Position;
	EmitVertex();

	gl_Position = gl_in[1].gl_Position;
	EmitVertex();

	//gl_Position = 0.5 * (gl_in[0].gl_Position +  gl_in[1].gl_Position);
	//gl_Position.y = gl_Position.y + gl_in[0].gl_Position.y +  gl_in[1].gl_Position.x;
	//EmitVertex();

	EndPrimitive();
}