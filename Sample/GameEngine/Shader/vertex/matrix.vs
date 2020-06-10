#version 330 core

uniform mat4 projectMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

#define MVP projectMatrix * viewMatrix * modelMatrix
#define MV projectMatrix * viewMatrix