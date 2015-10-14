#pragma once
#include "CameraComponent.h"
#include "Systems.h"
#include <map>

class Locator
{
public:
	static CameraComponent* GetMainCamera();

	static void Provide(CameraComponent* a_mainCamera);

	static void RegisterSystem(std::string a_entryName, System* a_service);

	static System* RetrieveSystem(std::string a_systemName);

private:
	static CameraComponent* m_mainCamera;
	static std::map<std::string, System*> m_services;
};