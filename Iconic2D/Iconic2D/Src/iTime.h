#pragma once
class Time
{
private:
	static float prevTime;
	static float currTime;
	static float deltaTime;
	
public:
	Time();
	~Time();

	static void Update();
	static float GetDeltaTime();
};

