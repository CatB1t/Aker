#ifndef _RENDERER_MESH_H_
#define _RENDERER_MESH_H_

#include <vector>
#include <memory>

#include "vertex.h"
#include "vertex_buffer.h"
#include "shaders/ShaderProgram.h"

namespace aker {

	class Mesh {
	public:
		Mesh();
		Mesh(std::vector<Vertex>& verts);
		~Mesh();

		void SetVerts(std::vector<Vertex>& verts);
		void Draw();
	private:
		std::unique_ptr<VertexBuffer> buffer_;
		std::unique_ptr<ShaderProgram> shader_program_;
		std::vector<Vertex> verts_;
	};

}

#endif