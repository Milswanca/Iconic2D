#pragma once
#include "GameObject.h"

class SpriteComponent;
class Application;
struct Material;

class TestObject : public GameObject
{
private:
	SpriteComponent* m_spriteComponent;

public:
	TestObject(Material a_mat);
	~TestObject();
};

