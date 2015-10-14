#pragma once
#include "Component.h"

class CameraComponent : public PhysicalComponent
{
private:
	glm::mat4 m_projectionView;

	bool m_isMainCamera;

public:
	CameraComponent();
	~CameraComponent();

	void Init(){};
	virtual void Update(float a_dt){};

	void SetAsMainCamera();
	void RemoveAsMainCamera();
	void SetProjectionMatrix(float a_screenWidth, float a_screenHeight, float near, float far);
	void Translate(glm::vec2 a_amount);

	glm::mat4* GetProjectionView();
};

