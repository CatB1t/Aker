#ifndef _SHADER_SHADER_H_
#define _SHADER_SHADER_H_

#include <string>
#include <unordered_map>

#include "glad/gl.h"
#include "../renderer/IBase.h"
#include "../utils/Logger.h"

namespace aker {
	enum class ShaderType {
		kVert,
		kFrag
	};

	class Shader : public IBase {
	public:
		Shader(const std::string& path);
		~Shader();
		const std::string& GetSourceCode() const;

		void Bind() const override {};
		void Unbind() const override {};
	private:
		inline const static std::string SHADERS_ROOT = SHADERS_ROOT_ABS_PATH;
		inline const static std::unordered_map<std::string, ShaderType> shader_str_to_enum_ = 
		{
			{".vert", ShaderType::kVert},
			{".vertex", ShaderType::kVert},

			{".frag", ShaderType::kFrag},
			{".fragment", ShaderType::kFrag}
		};

		inline const static std::unordered_map<ShaderType, GLenum> shader_enum_to_internal_ = 
		{
			{ShaderType::kVert, GL_VERTEX_SHADER},
			{ShaderType::kFrag, GL_FRAGMENT_SHADER}
		};

		void Init_();
		void LoadSrcFile_();
		void Compile_();
		void Create_() override;
		void Delete_() override;

		std::string path_;
		std::string name_;
		std::string src_code_;
		ShaderType type_;
		Logger logger_;
	};

}

#endif