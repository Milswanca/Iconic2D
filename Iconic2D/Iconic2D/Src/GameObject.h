#pragma once
#include "Component.h"
#include <vector>

class GameObject
{
public:
	GameObject();
	~GameObject();

	Component* GetComponent(unsigned int a_ID);
	void AddComponent(Component* a_comp);
	bool HasComponent(unsigned int a_ID);

	void Update(float dt);

private:
	std::vector<Component*> m_components;
};

