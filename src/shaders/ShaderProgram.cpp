#include "ShaderProgram.h"

namespace aker {

	ShaderProgram::ShaderProgram()
		: logger_ ("ShaderProgram")
	{
		Create_();
		Bind();
	}

	ShaderProgram::ShaderProgram(Shader& vertex, Shader& fragment)
	: ShaderProgram()
	{
		AttachShader(vertex);
		AttachShader(fragment);
	}

	ShaderProgram::~ShaderProgram()
	{
		Delete_();
	}

	void ShaderProgram::Bind() const
	{
		glUseProgram(GetId());
	}

	void ShaderProgram::Unbind() const
	{
		glUseProgram(0);
	}

	bool ShaderProgram::Link()
	{
		glLinkProgram(GetId());

		int link_status;
		glGetProgramiv(GetId(), GL_LINK_STATUS, &link_status);
		if (!link_status)
		{
			int log_length;
			glGetProgramiv(GetId(), GL_INFO_LOG_LENGTH, &log_length);

			char* log_str = (char *)malloc(sizeof(char) * log_length);
			glGetProgramInfoLog(GetId(), log_length, &log_length, log_str);
			logger_.Error("===== failed to link ====");
			logger_.Error("\n\n%s", log_str);
			logger_.Error("===== end ====");

			free(log_str);
			return false;
		}

		logger_.Info("Linked shader program %i", GetId());
		return true;
	}

	void ShaderProgram::AttachShader(Shader& shader)
	{
		shaders_.insert({ shader.GetType(), shader });

		Shader& s = shaders_.at(shader.GetType());
		s.Build();
		glAttachShader(GetId(), s.GetId());

		logger_.Info("Attached shader with ID: %i", s.GetId());
	}

	void ShaderProgram::Create_()
	{
		SetId_(glCreateProgram());
	}

	void ShaderProgram::Delete_()
	{
		glDeleteProgram(GetId());
		SetId_(-1);
	}

}
