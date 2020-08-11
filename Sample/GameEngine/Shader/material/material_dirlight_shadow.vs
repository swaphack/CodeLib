#version 330 core

#include "Shader/core/matrix.vs"
#include "Shader/core/light.vs"
#include "Shader/core/vertex.vs"

uniform Matrix matrix;
uniform LightSpace lightSpace;

out vec2 fragTexcoord;
out vec3 fragPosition;
out vec3 fragNormal;
out vec4 fragPosLightSpace;

void main()
{
	vec4 pos = vec4(v_position, 1.0);
	vec4 fragPos = matrix.model * pos;
	fragNormal = matrix.normal * v_normal;
	fragTexcoord = v_texcoord;
	fragPos = lightSpace.spaceMatrix * fragPos;

	gl_Position = get_mvp(matrix) * pos;
	fragPosition = fragPos.xyz;
}