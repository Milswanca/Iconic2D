#include "TestObject.h"
#include "Application.h"
#include "SpriteComponent.h"
#include "TextureLibrary.h"

TestObject::TestObject(Material a_mat)
{
	m_spriteComponent = new SpriteComponent();
	m_spriteComponent->Init();
	m_spriteComponent->SetMaterial(a_mat);
	AddComponent(m_spriteComponent);
}

TestObject::~TestObject()
{
	delete m_spriteComponent;
}