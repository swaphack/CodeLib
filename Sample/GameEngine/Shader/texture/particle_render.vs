#version 330 core

#include "Shader/core/matrix.vs"
#include "Shader/core/vertex.vs"

uniform Matrix matrix;


 //输出
out vec3 worldSpacePosition;
out vec3 fragNormal;

void main(void)
{
	vec4 position = matrix.model * vec4(v_texcoord, 1.0);
	
	worldSpacePosition = position.xyz;

    fragNormal = normalize((matrix.model * vec4(v_normal, 0)).xyz);
    
    gl_Position = matrix.project * position;
}