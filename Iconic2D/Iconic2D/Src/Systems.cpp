#include "Systems.h"
#include "Locator.h"
#include "CameraComponent.h"

void System::Register(Component* a_component)
{
	//If the component isnt already there
	if (std::find(m_components.begin(), m_components.end(), a_component) == m_components.end())
	{
		m_components.push_back(a_component);
	}
}

void Graphics::Init()
{
	m_mainCamera = Locator::GetMainCamera();
}

void Graphics::Render(float a_dt)
{
	for (auto c : m_components)
	{
		c->Render(a_dt, (*m_mainCamera->GetProjectionView()));
	}
}

void Graphics::RevalidateMembers()
{
	m_mainCamera = Locator::GetMainCamera();
}