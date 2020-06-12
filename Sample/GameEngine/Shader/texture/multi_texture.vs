#version 330 core

#include "Shader/core/matrix.vs"
#include "Shader/core/vertex.vs"

uniform Matrix matrix;

out vec2 fragTexcoord;
out vec4 fragColor;

void main()
{
	vec4 pos = vec4(v_position, 1.0);
	gl_Position = get_mvp(matrix) * pos;
	
    fragTexcoord = v_texcoord;
    fragColor = v_color;	
}