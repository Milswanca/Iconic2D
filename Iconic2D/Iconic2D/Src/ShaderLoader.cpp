#include "ShaderLoader.h"
#include <fstream>

ShaderLoader::ShaderLoader()
{
}

ShaderLoader::~ShaderLoader()
{
}

int ShaderLoader::LoadShader(const char* a_directory, GLenum a_shaderType)
{
	char* data;

	std::streampos size;
	std::ifstream file(a_directory, std::ios::in | std::ios::binary | std::ios::ate);
	
	if (file.is_open())
	{
		size = file.tellg();
		
		data = new char[(unsigned int)size + 1];
		data[(unsigned int)size] = '\0';

		file.seekg(0, std::ios::beg);
		file.read(data, size);
		file.close();
	}
	unsigned int shader = glCreateShader(a_shaderType);
	glShaderSource(shader, 1, (const char**)&data, 0);
	glCompileShader(shader);

	delete[] data;

	return shader;
}

int ShaderLoader::CreateProgram(int a_vsh, int a_fsh)
{
	int success = GL_FALSE;
	int programID = glCreateProgram();

	glAttachShader(programID, a_vsh);
	glAttachShader(programID, a_fsh);
	glLinkProgram(programID);

	glGetProgramiv(programID, GL_LINK_STATUS, &success);

	if (success == GL_FALSE) {
		int infoLogLength = 0;
		glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);
		char* infoLog = new char[infoLogLength];
		glGetProgramInfoLog(programID, infoLogLength, 0, infoLog);
		printf("Error: Failed to link shader program!\n");
		printf("%s\n", infoLog);
		delete[] infoLog;
	}

	return programID;
}

void ShaderLoader::DiscardShader(int a_shader)
{
	glDeleteShader(a_shader);
}