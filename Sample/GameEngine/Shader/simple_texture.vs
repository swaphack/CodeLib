#version 330 core

#include "Shader/vertex/matrix.vs"
#include "Shader/vertex/vertex.vs"

uniform Matrix matrix;


out vec2 fragmentUV;
out vec3 fragmentNormal;
out vec3 fragmentPos;

void main()
{
	vec4 pos = vec4(v_position, 1.0);
    gl_Position = get_mvp(matrix) * pos;

	fragmentPos = vec3(matrix.model * pos);
    fragmentUV = v_texcoord;
    fragmentNormal = mat3(transpose(inverse(matrix.model))) * v_normal; 
}