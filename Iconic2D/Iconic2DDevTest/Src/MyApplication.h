#pragma once
#include "Application.h"
#include <vector>

class TestObject;
class Camera;

class MyApplication : public Application
{
private:
	int program;

	Camera* m_camera;
	std::vector<TestObject*> m_objects;

public:
	MyApplication();
	~MyApplication();

	void Init();
	void Deinit();
	void Update(const float dt); 
	void Draw(const float dt);
};

