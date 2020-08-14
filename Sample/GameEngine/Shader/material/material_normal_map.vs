#version 330 core

#include "Shader/core/vertex/matrix.vs"
#include "Shader/core/vertex/vertex.vs"

uniform Matrix matrix;

out vec2 fragTexcoord;
out vec3 fragPos;
out mat3 fragTBN;

void main()
{
	vec4 pos = vec4(v_position, 1.0);

	gl_Position = getMVP(matrix) * pos;

	fragTexcoord = v_texcoord;
	fragPos = vec3(matrix.model * pos);

	vec3 T = matrix.normal * v_tangent;
	vec3 N = matrix.normal * v_normal;

	T = normalize(T - dot(T, N) * N);
	vec3 B = cross(N, T);

	fragTBN = transpose(mat3(T, B, N));

	fragPos = fragTBN * fragPos;
}