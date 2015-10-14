#include "MyApplication.h"
#include "TestObject.h"
#include "Camera.h"
#include <iostream>

MyApplication::MyApplication()
{
	
}

MyApplication::~MyApplication()
{

}

void MyApplication::Init()
{
	int vs = m_shaderLoader->LoadShader("./Content/Default.vsh", GL_VERTEX_SHADER);
	int fs = m_shaderLoader->LoadShader("./Content/Default.fsh", GL_FRAGMENT_SHADER);
	program = m_shaderLoader->CreateProgram(vs, fs);
	m_shaderLoader->DiscardShader(vs);
	m_shaderLoader->DiscardShader(fs);

	Texture* texture = m_textureLibrary->LoadTexture("./Content/TestSprite.png");

	std::cout << "Test 1: 10000 objects" << std::endl;

	m_camera = new Camera();

	for (int i = 0; i < 1; ++i)
	{
		Material mat;
		mat.texture = texture;
		mat.program = program;

		TestObject* newObject = new TestObject(mat);
		m_objects.push_back(newObject);
	}
}

void MyApplication::Deinit()
{
	for (auto iter = m_objects.begin(); iter != m_objects.end(); iter++)
	{
		delete (*iter);
	}
}

void MyApplication::Update(float dt)
{
	m_camera->MyUpdate(dt);
	m_camera->Update(dt);
}

void MyApplication::Draw(float dt)
{
	for (auto iter = m_objects.begin(); iter != m_objects.end(); iter++)
	{
		(*iter)->Update(dt);
	}
}