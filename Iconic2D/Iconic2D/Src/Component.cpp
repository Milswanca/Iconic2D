#include "Component.h"
#include "ext.hpp"

void PhysicalComponent::AttachTo(PhysicalComponent* a_other)
{
	m_parent = a_other;
	a_other->AddChild(this);
}

void PhysicalComponent::AddChild(PhysicalComponent* a_other)
{
	if (std::find(m_children.begin(), m_children.end(), a_other) != m_children.end())
	{
		m_children.push_back(a_other);
	}
}

void PhysicalComponent::RotateDeg(float a_amount)
{
	m_transform = glm::rotate(m_transform, a_amount, glm::vec3(0, 0, 1));
}

void PhysicalComponent::Translate(glm::vec2 a_amount)
{
	m_transform[2].xy += a_amount;
}

void PhysicalComponent::SetRotationDeg(float a_value)
{

}

void PhysicalComponent::SetTranslation(glm::vec2 a_value)
{

}

void PhysicalComponent::SetScale(glm::vec2 a_value)
{
	m_transform = glm::scale(m_transform, glm::vec3(a_value, 1));
}

void PhysicalComponent::SetTransform(glm::mat4 a_value)
{
	m_transform = a_value;
}

float PhysicalComponent::GetRotationDeg()
{
	return 1;
}

glm::vec2 PhysicalComponent::GetTranslation()
{
	return m_transform[2].xy;
}

glm::vec2 PhysicalComponent::GetScale()
{
	return glm::vec2();
}

glm::mat4 PhysicalComponent::GetTransform()
{
	return m_transform;
}