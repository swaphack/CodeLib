#version 330 core

#include "Shader/core/vertex/matrix.vs"
#include "Shader/core/vertex/light.vs"
#include "Shader/core/vertex/vertex.vs"

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
	fragPosLightSpace = lightSpace.spaceMatrix * fragPos;

	gl_Position = getMVP(matrix) * pos;
	fragPosition = fragPos.xyz;

	//fragPosLightSpace = matrix.project * matrix.view * fragPos;
}