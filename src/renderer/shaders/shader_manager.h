#ifndef _RENDERER_SHADERS_SHADER_MANAGER_H_
#define _RENDERER_SHADERS_SHADER_MANAGER_H_

#include <unordered_map>
#include <memory>
#include <string>

#include "Shader.h"
#include "ShaderProgram.h"

namespace aker {

	class ShaderManager {
	public:
		void Create(const std::string& name, const std::string& s1, const std::string& s2);
		void Add(const std::string& name, std::unique_ptr<ShaderProgram>&& shader);
		void Delete(const std::string& name);
		ShaderProgram* Get(const std::string& name);
	private:
		std::unordered_map<std::string, std::unique_ptr<ShaderProgram>> compiled_shader_programs_;

	};
}

#endif