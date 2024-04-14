#include "Shader.h"

#include <sstream>
#include <fstream>
#include <format>
#include <filesystem>

namespace aker {

	Shader::Shader(const std::string& path)
		: path_(path), logger_("Shader")
	{
		Init_();
		Create_();
		logger_.Info(
			"Loading %s with type %s from %s", 
			name_.c_str(),
			((type_ == ShaderType::kFrag) ? "fragment" : "vertex"), // TODO use a helper function
			path_.c_str()
		);
	}

	Shader::~Shader()
	{
		Delete_();
	}

	const std::string& Shader::GetSourceCode() const
	{
		return src_code_;
	}

	ShaderType Shader::GetType() const
	{
		return type_;
	}

	void Shader::Init_() 
	{
		std::filesystem::path shader_path{ path_ };

		if (shader_path.is_relative())
		{
			std::filesystem::path new_path = SHADERS_ROOT;
			new_path += shader_path;
			shader_path = new_path;
			path_ = shader_path.string();
		}

		name_ = shader_path.filename().string();
		type_ = shader_str_to_enum_.at(shader_path.extension().string());
	}

	void Shader::LoadSrcFile_()
	{
		std::fstream src_file;
		src_file.open(path_, std::fstream::in);

		std::stringstream str_buffer;
		str_buffer << src_file.rdbuf();

		src_file.close();
		src_code_ = str_buffer.str();
	}

	void Shader::Compile_()
	{
		glCompileShader(GetId());
		int status;
		glGetShaderiv(GetId(), GL_COMPILE_STATUS, &status);
		if (status != GL_TRUE)
		{
			int log_length;
			glGetShaderiv(GetId(), GL_INFO_LOG_LENGTH, &log_length);

			char* str = (char*)malloc(sizeof(char) * log_length);
			glGetShaderInfoLog(GetId(), log_length, &log_length, str);

			logger_.Error("===== %s failed to compile ====", name_.c_str());
			logger_.Error("\n\n%s", str);
			logger_.Error("===== %s end =====", name_.c_str());
			free(str);
		}
		else {
			logger_.Info("Compiled %s successfully", name_.c_str());
		}
	}

	void Shader::Create_()
	{
		SetId_(glCreateShader(shader_enum_to_internal_.at(type_)));

		LoadSrcFile_();
		const char* src = src_code_.c_str();
		glShaderSource(GetId(), 1, &src, nullptr);

		Compile_();
	}

	void Shader::Delete_()
	{
		glDeleteShader(GetId());
	}

};