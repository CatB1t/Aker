#ifndef _RENDERER_MESH_H_
#define _RENDERER_MESH_H_

#include <vector>
#include <memory>

#include "glm/glm.hpp"

#include "vertex.h"
#include "vertex_buffer.h"
#include "shaders/ShaderProgram.h"
#include "camera.h"

namespace aker {

	class Mesh {
	public:
		Mesh(const std::string& name = "Unnamed");
		Mesh(std::vector<Vertex>& verts, const std::string& name = "Unnamed");
		~Mesh();

		void SetVerts(std::vector<Vertex>& verts);
		void Draw(ShaderProgram* shader_program, const Camera& camera);
		const std::string& GetName() const { return name_; };
		void ShowDebugMenu() const;

	private:
		std::string name_;
		std::unique_ptr<VertexBuffer> buffer_;
		std::vector<Vertex> verts_;

		glm::vec3 position_ { 0.0f };
		glm::vec3 rotation_ { 0.0f };
	};

}

#endif