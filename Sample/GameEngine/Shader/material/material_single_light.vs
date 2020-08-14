#version 330 core

#include "Shader/core/vertex/matrix.vs"
#include "Shader/core/vertex/vertex.vs"

uniform Matrix matrix;

out vec2 fragTexcoord;
out vec3 fragNormal;
out vec3 fragPos;

void main()
{
	vec4 pos = vec4(v_position, 1.0);
    gl_Position = getMVP(matrix) * pos;

	fragPos = vec3(matrix.model * pos);
    fragTexcoord = v_texcoord;
    fragNormal = matrix.normal * v_normal; 
}