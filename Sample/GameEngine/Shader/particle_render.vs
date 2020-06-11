#version 330 core

#include "Shader/vertex/matrix.vs"
#include "Shader/vertex/vertex.vs"

uniform Matrix matrix;


 //输出
out vec3 worldSpacePosition;
out vec3 fragmentNormal;

void main(void)
{
	vec4 position = matrix.model * vec4(v_texcoord, 1.0);
	worldSpacePosition = position.xyz;

    fragmentNormal = normalize((matrix.model * vec4(v_normal, 0)).xyz);
    
    gl_Position = matrix.project * position;
}