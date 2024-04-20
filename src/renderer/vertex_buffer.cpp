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
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, Vertex::Size(), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, Vertex::Size(), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		// TODO end refactor
		Unbind();
	}

	VertexBuffer::VertexBuffer(std::vector<Vertex>& data)
		: VertexBuffer()
	{
		SetData(data);
	}

	VertexBuffer::~VertexBuffer()
	{
		Unbind();
		Delete_();
	}

	void VertexBuffer::SetData(std::vector<Vertex>& data)
	{
		Bind();
		glBufferData(GL_ARRAY_BUFFER, Vertex::Size() * data.size(), std::data(data), GL_STATIC_DRAW);
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