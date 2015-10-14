/// Date Created: 10/10/2015 at 1:58pm
/// Author: Justin Kiesskalt

/// Description: Main entry point of the program

#include <gl_core_4_4.h>
#include <glfw3.h>

#include "ShaderLoader.h"
#include "TextureLibrary.h"

class Time;
class Graphics;

#pragma once
class Application
{
private:
	/// Determines whether or not to close the engine each frame
	bool m_shouldKill;
	Time* m_time;

	Graphics* m_graphicsSystem;

protected:
	GLFWwindow* appWindow;
	ShaderLoader* m_shaderLoader;
	TextureLibrary* m_textureLibrary;

public:
	Application();
	~Application();

	/// \brief Creates a new Window with the specified width, height and title, TODO: Make fullscreen work
	/// \return Error code of the created window. -1: opengl not initialized. -2: window failed to create, 1: success. TODO: Add a window manager
	int CreateNewWindow(const unsigned int a_width, const unsigned int a_height, const char* a_title = "", const bool a_fullscreen = false);

	/// \brief Starts the applications update events
	void Run();

	/// \brief Kills the engines execution
	void Kill();

	/// \brief Called on derived classes for engine initiation
	virtual void Init() {};

	/// \brief Called on derived classes before the engine closes. Used for cleanup
	virtual void Deinit() {};

	/// \brief Update loop for derived classes
	virtual void Update(const float a_dt) {};

	/// \brief Draw loop for derived classes
	virtual void Draw(const float a_dt) {};
};