#include "SpriteComponent.h"
#include "gl_core_4_4.h"
#include "glfw3.h"
#include "Application.h"
#include "ext.hpp"
#include "Locator.h"

#include "TextureLibrary.h"

SpriteComponent::SpriteComponent()
{
	m_material = Material();
	m_transform = glm::mat4(1);

	Locator::RetrieveSystem("Graphics")->Register(this);
}


SpriteComponent::~SpriteComponent()
{

}

void SpriteComponent::Init()
{
	Vertex* vertexData = new Vertex[4];

	vertexData[0].position = vec2(0, 1);
	vertexData[1].position = vec2(1, 1);
	vertexData[2].position = vec2(1, 0);
	vertexData[3].position = vec2(0, 0);
	vertexData[0].colour = vec4(1, 0, 0, 1);
	vertexData[1].colour = vec4(0, 1, 0, 1);
	vertexData[2].colour = vec4(0, 0, 1, 1);
	vertexData[3].colour = vec4(0, 1, 1, 1);
	vertexData[0].texCoords = vec2(0, 0);
	vertexData[1].texCoords = vec2(1, 0);
	vertexData[2].texCoords = vec2(1, 1);
	vertexData[3].texCoords = vec2(0, 1);

	unsigned int indices[] = { 
		0, 1, 2, 2, 3, 0
	};

	// Generate our GL Buffers
	// Lets move these so that they are all generated together
	glGenBuffers(1, &m_vbo);
	glGenBuffers(1, &m_ibo);

	//Add the following line to generate a VertexArrayObject
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex), vertexData, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);//Position
	glEnableVertexAttribArray(1);//Colour
	glEnableVertexAttribArray(2);//UVs

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(glm::vec2)));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)((sizeof(glm::vec2)) + (sizeof(glm::vec4))));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	delete[] vertexData;
}

void SpriteComponent::SetMaterial(Material a_material)
{
	m_material = a_material;
	SetScale(glm::vec2(m_material.texture->GetWidth(), m_material.texture->GetHeight()));
}

void SpriteComponent::Render(float a_dt, glm::mat4& a_projectionView)
{
	glUseProgram(m_material.program);

	int loc = glGetUniformLocation(m_material.program, "Diffuse");
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_material.texture->GetID());
	glUniform1i(loc, 0);

	loc = glGetUniformLocation(m_material.program, "Transform");
	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(GetTransform()));

	loc = glGetUniformLocation(m_material.program, "Projection");
	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(a_projectionView));

	glBindVertexArray(m_vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}