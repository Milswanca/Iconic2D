#include "Locator.h"
#include "Systems.h"

CameraComponent* Locator::m_mainCamera = nullptr;
std::map<std::string, System*> Locator::m_services = std::map<std::string, System*>();

CameraComponent* Locator::GetMainCamera()
{
	return m_mainCamera;
}

void Locator::Provide(CameraComponent* a_mainCamera)
{
	m_mainCamera = a_mainCamera;

	for (auto s : m_services)
	{
		s.second->RevalidateMembers();
	}
}

void Locator::RegisterSystem(std::string a_entryName, System* a_service)
{
	m_services.insert(std::make_pair(a_entryName, a_service));
}

System* Locator::RetrieveSystem(std::string a_systemName)
{
	return m_services[a_systemName];
}