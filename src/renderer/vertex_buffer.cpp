#include "vertex_buffer.h"

#include <vector>

#include "glad/gl.h"

namespace aker {

	VertexBuffer::VertexBuffer()
	{
		Create_();
		Bind();

		glBindBuffer(GL_ARRAY_BUFFER, vbo_);
		// TODO refactor, should not be hard coded but dynamically retrieved
		// from Vertex struct
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
		// TODO end refactor
		Unbind();
	}

	VertexBuffer::VertexBuffer(std::vector<Vertex>& data)
		: VertexBuffer()
	{
		Bind();
		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * data.size(), std::data(data), GL_STATIC_DRAW);
		Unbind();
	}

	VertexBuffer::~VertexBuffer()
	{
		Unbind();
		Delete_();
	}

	void VertexBuffer::SetData(std::vector<Vertex>& data)
	{
		Bind();
		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * data.size(), std::data(data), GL_STATIC_DRAW);
		Unbind();
	}

	void VertexBuffer::Bind()
	{
		glBindVertexArray(vao_);
	}

	void VertexBuffer::Unbind()
	{
		glBindVertexArray(0);
	}

	void VertexBuffer::Create_()
	{
		glGenVertexArrays(1, &vao_);
		glGenBuffers(1, &vbo_);
	}

	void VertexBuffer::Delete_()
	{
		glDeleteBuffers(1, &vbo_);
		glDeleteVertexArrays(1, &vao_);
	}

}