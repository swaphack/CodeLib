#version 330 core

#include "Shader/core/texture.fs"

uniform Texture tex;

in vec2 fragTexcoord;
in vec4 fragColor;

out vec4 color;

void main()
{    
    color = fragColor * texture(tex.texture0, fragTexcoord);

    //color = vec4(1, 1, 1, 1);
}