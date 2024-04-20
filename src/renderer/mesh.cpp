#include "mesh.h"

#include "imgui/imgui.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

namespace aker {

	Mesh::Mesh(const std::string& name)
		: name_(name)
	{
		shader_program_ = std::make_unique<ShaderProgram>();
		shader_program_->Link();
		buffer_ = std::make_unique<VertexBuffer>();
	}

	Mesh::Mesh(std::vector<Vertex>& verts, const std::string& name)
		: verts_(verts), name_(name)
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

	void Mesh::Draw(const Camera& camera)
	{
		shader_program_->Bind();
		shader_program_->SetUniform("pv", camera.GetMatrix());
		glm::mat4 model_transform{ 1.0f };
		model_transform = glm::translate(model_transform, position_);
		shader_program_->SetUniform("model", model_transform);
		buffer_->Bind();
		glDrawArrays(GL_TRIANGLES, 0, verts_.size());
		buffer_->Unbind();
		shader_program_->Unbind();
	}

	void Mesh::ShowDebugMenu() const
	{
		ImGui::Text(name_.c_str());
		// TODO not sure if that is safe
		ImGui::InputText("Name", (char*)name_.c_str(), name_.capacity());
		ImGui::DragFloat3("Position", (float*)glm::value_ptr(position_), 0.01f, -100.0f, 100.0f);
	}

}