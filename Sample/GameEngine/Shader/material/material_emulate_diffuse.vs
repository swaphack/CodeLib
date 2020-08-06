#version 330 core

#include "Shader/core/matrix.vs"
#include "Shader/core/vertex.vs"
#include "Shader/core/emulate_light.vs"

uniform Matrix matrix;

out vec3 fragColor;
out vec2 fragTexcoord;

void main()
{
	vec4 pos = vec4(v_position, 1.0);

	gl_Position = get_mvp(matrix) * pos;

	vec3 normal = matrix.normal * v_normal;
	fragColor = getLightOldTownEmulateDiffuseLight(normal);

	fragTexcoord = v_texcoord;
}