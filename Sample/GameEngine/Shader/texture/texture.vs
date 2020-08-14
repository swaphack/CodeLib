#version 330 core

#include "Shader/core/vertex/vertex.vs"
#include "Shader/core/vertex/matrix.vs"

uniform Matrix matrix;

out vec2 fragTexcoord;

void main()
{
	vec4 pos = vec4(v_position, 1.0);

	gl_Position = getMVP(matrix) * pos;

	fragTexcoord = v_texcoord;
}
