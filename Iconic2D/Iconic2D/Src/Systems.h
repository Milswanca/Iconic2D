#pragma once
#include <vector>

class Component;
class CameraComponent;

class System
{
protected:
	std::vector<Component*> m_components;

public:
	System() {};
	
	// All systems must update each game loop
	virtual void Update(float dt) = 0;

	virtual void Render(float dt) = 0;

	virtual void RevalidateMembers() = 0;

	// It's good practice to separate the construction and initialization code.
	virtual void Init(void) = 0;

	void Register(Component* a_component);

	// This recieves any messages sent to the core engine in Engine.cpp
	//virtual void SendMessage(Message *msg) = 0;

	///All systems need a virtual destructor to have their destructor called 
	virtual ~System() {}
};

class Graphics : public System
{
private:
	CameraComponent* m_mainCamera;

public:
	Graphics() {};
	virtual ~Graphics() {};

	void Update(float a_dt) {};
	void Render(float a_dt);

	void RevalidateMembers();

	void Init();
};