#pragma once
#include "glm.hpp"
#include "Component.h"
#include "TextureLibrary.h"

class Application;

using glm::vec2;
using glm::vec3;
using glm::vec4;

struct Vertex
{
	vec2 position;
	vec4 colour;
	vec2 texCoords;
};

class SpriteComponent : public RenderableComponent
{
private:
	unsigned int m_vao, m_vbo, m_ibo;

	Material m_material;

public:
	//Overrides
	void Init();
	void Update(float a_dt) {};
	void Render(float a_dt, glm::mat4& a_projectionView);

	SpriteComponent();
	~SpriteComponent();

	void SetMaterial(Material a_material);
};

