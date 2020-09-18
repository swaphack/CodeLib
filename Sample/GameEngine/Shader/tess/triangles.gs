#version 330 core

layout (triangles) in;
layout (triangle_strip, max_vertices=3) out;

out vec2 fragTexcoord;

in vec2 gsTexcoord[];

void main()
{
	gl_Position = gl_in[0].gl_Position;
	fragTexcoord = gsTexcoord[0];
	EmitVertex();

	gl_Position = gl_in[1].gl_Position;
	fragTexcoord = gsTexcoord[1];
	EmitVertex();

	gl_Position = gl_in[2].gl_Position;
	fragTexcoord = gsTexcoord[2];
	EmitVertex();

	
	EndPrimitive();
}