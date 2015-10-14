#version 410

layout(location=0) in vec2 Position;
layout(location=1) in vec4 Colour;
layout(location=2) in vec2 TexCoords;

out vec4 vColour;
out vec2 vTexCoords;

uniform mat4 Transform;
uniform mat4 Projection;

void main() 
{
	vTexCoords = TexCoords; 
	vColour = Colour;
	gl_Position = Projection * Transform * vec4(Position, 0, 1);
}