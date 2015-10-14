#pragma once
#include <map>
#include <string>

#include <gl_core_4_4.h>
#include <glfw3.h>

class ShaderLoader
{
private:
	std::map<std::string, int> m_programs;

public:
	ShaderLoader();
	~ShaderLoader();

	int LoadShader(const char* a_directory, GLenum a_shaderType);
	int CreateProgram(int a_vsh, int a_fsh);
	void DiscardShader(int a_shader);
};

