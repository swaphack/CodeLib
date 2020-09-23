#version 330 core

layout (triangles) in;
layout (triangle_strip, max_vertices=3) out;

out vec2 fragTexcoord;
out vec3 fragColor;

in vec2 gsTexcoord[];
in vec3 gsColor[];

void main()
{
	gl_Position = gl_in[0].gl_Position;
	fragTexcoord = gsTexcoord[0];
	fragColor = gsColor[0];
	EmitVertex();

	gl_Position = gl_in[1].gl_Position;
	fragTexcoord = gsTexcoord[1];
	fragColor = gsColor[1];
	EmitVertex();

	gl_Position = gl_in[2].gl_Position;
	fragTexcoord = gsTexcoord[2];
	fragColor = gsColor[2];
	EmitVertex();

	
	EndPrimitive();
}