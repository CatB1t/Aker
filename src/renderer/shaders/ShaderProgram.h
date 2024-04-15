#ifndef _SHADER_SHADERPROGRAM_H_
#define _SHADER_SHADERPROGRAM_H_

#include <unordered_map>
#include <string>

#include "../IBase.h"
#include "../../utils/Logger.h"
#include "Shader.h"

namespace aker {

	class ShaderProgram : public IBase {
	public:
		ShaderProgram();
		ShaderProgram(Shader& vertex, Shader& fragment);
		~ShaderProgram();

		void Bind() const override;
		void Unbind() const override;

		bool Link();
		void AttachShader(Shader& shader);
	private:
		void Create_() override;
		void Delete_() override;
		Logger logger_;
		std::unordered_map<ShaderType, Shader> shaders_;
	};

}

#endif