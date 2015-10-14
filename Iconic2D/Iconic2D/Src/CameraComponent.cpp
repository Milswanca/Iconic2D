#include "CameraComponent.h"
#include "glm.hpp"
#include "ext.hpp"
#include "Locator.h"
#include "Systems.h"

CameraComponent::CameraComponent()
{
	m_isMainCamera = false;
	Locator::RetrieveSystem("Graphics")->Register(this);
}


CameraComponent::~CameraComponent()
{
}

void CameraComponent::SetProjectionMatrix(float a_screenWidth, float a_screenHeight, float near, float far)
{
	m_projectionView = glm::ortho(0.0f, a_screenWidth, 0.0f, a_screenHeight);
}

void CameraComponent::Translate(glm::vec2 a_amount)
{
	m_projectionView[3].xy += a_amount;
}

glm::mat4* CameraComponent::GetProjectionView()
{
	return &m_projectionView;
}

void CameraComponent::SetAsMainCamera()
{
	//Locator::GetMainCamera()->RemoveAsMainCamera();
	m_isMainCamera = true;
	Locator::Provide(this);
}

void CameraComponent::RemoveAsMainCamera()
{
	m_isMainCamera = false;
}