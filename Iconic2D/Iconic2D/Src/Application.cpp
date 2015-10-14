#include "Application.h"
#include "iTime.h"
#include "Systems.h"
#include "Locator.h"

#include <string>

Application::Application()
{
	m_shouldKill = false;
	m_time = new Time();
	appWindow = nullptr;
	m_shaderLoader = new ShaderLoader();
	m_textureLibrary = new TextureLibrary();

	m_graphicsSystem = new Graphics();
	Locator::RegisterSystem("Graphics", m_graphicsSystem);
}


Application::~Application()
{
}

int Application::CreateNewWindow(const unsigned int a_width, const unsigned int a_height, const char* a_title, const bool a_fullscreen)
{
	//Init GLFW
	if (glfwInit() == false)
	{
		return -1;
	}

	//Create a new Window
	appWindow = glfwCreateWindow(a_width, a_height, a_title, nullptr, nullptr);

	//Check if the window is valid
	if (appWindow == nullptr) 
	{
		glfwTerminate();
		return -2;
	}

	//Make the window the current window
	glfwMakeContextCurrent(appWindow);

	//Load OpenGL functions
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED) 
	{
		glfwDestroyWindow(appWindow);
		glfwTerminate();
		return -3;
	}

	return 1;
}

void Application::Run()
{
	CreateNewWindow(640, 480, "Iconic2D");

	//Turn on Alpha blending (because its awesome)
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	//Set the background Colour
	glClearColor(0.5, 0.5, 0.5, 1);

	//Call load content for the engines children
	this->Init();

	//Main Loop
	while (!m_shouldKill && glfwWindowShouldClose(appWindow) == false)
	{
		//Refresh the Screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Store the delta time for this frame
		m_time->Update();
		float dt = m_time->GetDeltaTime();

		std::string fps = std::to_string(1.0f / dt);
		glfwSetWindowTitle(appWindow, fps.c_str());

		//Render
		m_graphicsSystem->Update(dt);
		m_graphicsSystem->Render(dt);

		//Update and draw children
		this->Update(dt);
		this->Draw(dt);

		//Swap the buffer with the back buffer
		glfwSwapBuffers(appWindow);
		glfwPollEvents();
	}

	delete m_time;
	delete m_shaderLoader;
	delete m_textureLibrary;

	this->Deinit();
	glfwTerminate();
}