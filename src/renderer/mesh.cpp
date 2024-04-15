#include "mesh.h"

namespace aker {

	Mesh::Mesh()
	{
		Shader vert{ "default.vert" };
		Shader frag{ "default.frag" };
		shader_program_ = std::make_unique<ShaderProgram>(vert, frag);
		buffer_ = std::make_unique<VertexBuffer>();
	}

	Mesh::Mesh(std::vector<Vertex>& verts)
		: verts_(verts)
	{
		Shader vert{ "default.vert" };
		Shader frag{ "default.frag" };
		shader_program_ = std::make_unique<ShaderProgram>(vert, frag);
		shader_program_->Link();
		buffer_ = std::make_unique<VertexBuffer>(verts_);
	}

	Mesh::~Mesh()
	{
	}

	void Mesh::Draw()
	{
		shader_program_->Bind();
		buffer_->Bind();
		glDrawArrays(GL_TRIANGLES, 0, verts_.size());
		buffer_->Unbind();
		shader_program_->Unbind();
	}

}