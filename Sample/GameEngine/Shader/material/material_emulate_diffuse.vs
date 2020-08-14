#version 330 core

#include "Shader/core/vertex/matrix.vs"
#include "Shader/core/vertex/vertex.vs"
#include "Shader/core/vertex/light.vs"

uniform Matrix matrix;

out vec3 fragColor;
out vec2 fragTexcoord;

void main()
{
	vec4 pos = vec4(v_position, 1.0);

	gl_Position = getMVP(matrix) * pos;

	vec3 normal = matrix.normal * v_normal;
	fragColor = getLightOldTownEmulateDiffuseLight(normal);

	fragTexcoord = v_texcoord;
}