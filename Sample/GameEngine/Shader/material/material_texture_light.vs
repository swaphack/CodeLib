#version 330 core

#include "Shader/core/vertex/matrix.vs"
#include "Shader/core/vertex/vertex.vs"

uniform Matrix matrix;

out vec3 fragReflectDir;
out vec3 fargNormal;
out vec2 fragTexcoord;

void main()
{
	vec4 pos = vec4(v_position, 1.0);
	fargNormal = normalize(matrix.normal * v_normal);
	vec4 eyePos = getMV(matrix) * pos;
	vec3 eyeDir = eyePos.xyz;
	fragReflectDir = reflect(eyeDir, fargNormal);
	fragTexcoord = v_texcoord;
	gl_Position = getMVP(matrix) * pos;
}