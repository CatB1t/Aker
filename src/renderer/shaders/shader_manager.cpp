#include "shader_manager.h"

namespace aker {

	void ShaderManager::Create(const std::string& name, const std::string& s1, const std::string& s2)
	{
		auto shader_program = std::make_unique<ShaderProgram>();
		auto shader1 = std::make_unique<Shader>(s1);
		auto shader2 = std::make_unique<Shader>(s2);
		shader_program->AttachShader(shader1);
		shader_program->AttachShader(shader2);
		shader_program->Link();
		compiled_shader_programs_[name] = std::move(shader_program);
	}

	void ShaderManager::Add(const std::string& name, std::unique_ptr<ShaderProgram>&& shader)
	{
		compiled_shader_programs_[name] = std::move(shader);
	}

	void ShaderManager::Delete(const std::string& name)
	{
		compiled_shader_programs_.erase(name);
	}

	ShaderProgram* ShaderManager::Get(const std::string& name)
	{
		return compiled_shader_programs_[name].get();
	}
}