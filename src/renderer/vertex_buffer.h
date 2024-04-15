#ifndef _RENDERER_VERTEX_BUFFER_H_
#define _RENDERER_VERTEX_BUFFER_H_

#include "vertex.h"

namespace aker {

	class VertexBuffer {
	public:
		VertexBuffer();
		VertexBuffer(std::vector<Vertex>& data);
		~VertexBuffer();

		void SetData(std::vector<Vertex>& data);
		void Bind();
		void Unbind();

	private:
		unsigned int vao_, vbo_;
		void Create_();
		void Delete_();
	};

}

#endif