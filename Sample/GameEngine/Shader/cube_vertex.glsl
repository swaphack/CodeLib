#version 330 core
layout (location = 0) in vec3 vPosition;
layout (location = 7) in vec3 vNormal;

out vec3 Normal;
out vec3 Position;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectMatrix;

void main()
{
    Normal = mat3(transpose(inverse(modelMatrix))) * vNormal;
    Position = vec3(modelMatrix * vec4(vPosition, 1.0));
    gl_Position = projectMatrix * viewMatrix * modelMatrix * vec4(vPosition, 1.0);
}