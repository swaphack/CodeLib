#version 330 core

#include "Shader/core/matrix.vs"
#include "Shader/core/vertex.vs"

uniform Matrix matrix;


out vec2 fragTexcoord;
out vec3 fragNormal;
out vec3 fragPos;

void main()
{
	vec4 pos = vec4(v_position, 1.0);
    gl_Position = get_mvp(matrix) * pos;

	fragPos = vec3(matrix.model * pos);
    fragTexcoord = v_texcoord;
    fragNormal = mat3(transpose(inverse(matrix.model))) * v_normal; 
}