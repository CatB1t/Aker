#include "ShaderProgram.h"

namespace aker {

	ShaderProgram::ShaderProgram(bool use_default)
		: logger_ ("ShaderProgram")
	{
		Create_();
		Bind();

		if (use_default)
		{
			std::unique_ptr<Shader> frag = std::make_unique<Shader>("default.vert");
			std::unique_ptr<Shader> vert = std::make_unique<Shader>("default.frag");
			AttachShader(vert);
			AttachShader(frag);
		}
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

	void ShaderProgram::AttachShader(std::unique_ptr<Shader>& shader)
	{
		auto type = shader->GetType();
		shaders_.insert({ type, std::move(shader) });

		std::unique_ptr<Shader>& newShader = shaders_[type];
		glAttachShader(GetId(), newShader->GetId());

		logger_.Info("Attached shader with ID: %i", newShader->GetId());
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
