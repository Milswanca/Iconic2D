#pragma once
#include "GameObject.h"

class CameraComponent;

class Camera : public GameObject
{
private:
	CameraComponent* m_cameraComponent;
public:
	Camera();
	~Camera();

	void MyUpdate(float dt);
};

