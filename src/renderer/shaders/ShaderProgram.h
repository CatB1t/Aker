#ifndef _SHADER_SHADERPROGRAM_H_
#define _SHADER_SHADERPROGRAM_H_

#include <memory>
#include <unordered_map>
#include <string>

#include "../IBase.h"
#include "../../utils/Logger.h"
#include "Shader.h"

namespace aker {

	class ShaderProgram : public IBase {
	public:
		ShaderProgram(bool use_default = true);
		~ShaderProgram();

		void Bind() const override;
		void Unbind() const override;

		bool Link();
		void AttachShader(std::unique_ptr<Shader>& shader);
	private:
		void Create_() override;
		void Delete_() override;
		Logger logger_;
		std::unordered_map<ShaderType, std::unique_ptr<Shader>> shaders_;
	};

}

#endif