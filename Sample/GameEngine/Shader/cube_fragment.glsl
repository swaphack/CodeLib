#version 330 core

uniform samplerCube texSampler0;

in vec2 fragmentUV;

out vec4 FragColor;

void main()
{    
    FragColor = texture(texSampler0, vec3(fragmentUV, 0));
}