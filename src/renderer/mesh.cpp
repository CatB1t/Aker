#include "mesh.h"

namespace aker {

	Mesh::Mesh()
	{
		shader_program_ = std::make_unique<ShaderProgram>();
		shader_program_->Link();
		buffer_ = std::make_unique<VertexBuffer>();
	}

	Mesh::Mesh(std::vector<Vertex>& verts)
		: verts_(verts)
	{
		shader_program_ = std::make_unique<ShaderProgram>();
		shader_program_->Link();
		buffer_ = std::make_unique<VertexBuffer>(verts_);
	}

	void Mesh::SetVerts(std::vector<Vertex>& verts)
	{
		verts_ = verts;
		buffer_->SetData(verts);
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