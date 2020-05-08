#version 330 core

// Interpolated values from the vertex shaders
in vec2 UV;
in vec4 Color;

// Ouput data
out vec4 color;

// Values that stay constant for the whole mesh.
uniform sampler2D texSampler;

void main(){

    // Output color = color of the texture at the specified UV
	color = Color * texture(texSampler, UV);
}