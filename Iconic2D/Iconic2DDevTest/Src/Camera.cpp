#include "Camera.h"
#include "CameraComponent.h"
#include "Locator.h"

Camera::Camera()
{
	m_cameraComponent = new CameraComponent();
	m_cameraComponent->Init();
	m_cameraComponent->SetProjectionMatrix(640, 480, 1, -1);
	m_cameraComponent->SetAsMainCamera();
	AddComponent(m_cameraComponent);
}

Camera::~Camera()
{
	delete m_cameraComponent;
}

void Camera::MyUpdate(float dt)
{
	m_cameraComponent->Translate(glm::vec2(dt / 10.0f, dt / 10.0f));
}