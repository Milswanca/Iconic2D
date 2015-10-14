#include "iTime.h"
#include <glfw3.h>

float Time::prevTime = 0;
float Time::deltaTime = 0;
float Time::currTime = 0;

Time::Time()
{
}


Time::~Time()
{
}

void Time::Update()
{
	//Calculate the current time, previous time and delta time from these 2 values
	currTime = (float)glfwGetTime();
	deltaTime = currTime - prevTime;
	prevTime = currTime;
}

float Time::GetDeltaTime()
{
	return deltaTime;
}
