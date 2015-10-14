#pragma once
#include "glm.hpp"
#include "gtx\matrix_transform_2d.hpp"
#include <vector>

class Component
{
public:
	virtual void Init() = 0;
	virtual void Update(float dt) = 0;
	virtual void Render(float dt, glm::mat4& a_projectionView) {};
	//virtual void SendMessage(/*Message*/) = 0; //TODO: Make this feature
	
	virtual ~Component() {};
};

// Components that have a transform and can be attached to other componenets
class PhysicalComponent : public Component
{
protected:
	glm::mat4 m_transform;

	std::vector<Component*> m_children;
	Component* m_parent;

public:
	virtual void Init() = 0;
	virtual void Update(float dt) = 0;
	virtual void Render(float dt, glm::mat4& a_projectionView) {};
	virtual ~PhysicalComponent() {};

	void AttachTo(PhysicalComponent* a_other);
	void AddChild(PhysicalComponent* a_other);

	void RotateDeg(float a_amount);
	void Translate(glm::vec2 a_amount);
	
	void SetRotationDeg(float a_value);
	void SetTranslation(glm::vec2 a_value);
	void SetScale(glm::vec2 a_value);
	void SetTransform(glm::mat4 a_value);

	float GetRotationDeg();
	glm::vec2 GetTranslation();
	glm::vec2 GetScale();
	glm::mat4 GetTransform();
};

// Components that have a transform, can be attached to other components AND be rendered to the screen
class RenderableComponent : public PhysicalComponent
{
public:
	virtual void Init() = 0;
	virtual void Update(float dt) = 0;
	virtual void Render(float a_dt, glm::mat4& a_projectionView) = 0;
};