#include "GameObject.h"


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

Component* GameObject::GetComponent(unsigned int a_ID)
{
	return m_components[a_ID];
}

void GameObject::AddComponent(Component* a_comp)
{
	m_components.push_back(a_comp);
}

bool GameObject::HasComponent(unsigned int a_ID)
{
	return true;
}

void GameObject::Update(float dt)
{
	for (auto c : m_components)
	{
		c->Update(dt);
	}
}