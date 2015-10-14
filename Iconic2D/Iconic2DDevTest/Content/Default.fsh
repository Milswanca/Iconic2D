#version 410

in vec4 vColour;
in vec2 vTexCoords;

out vec4 FragColor;

uniform sampler2D Diffuse;

void main() 
{ 
	FragColor = texture(Diffuse, vTexCoords) * vColour; 
}