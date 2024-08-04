#include "mesh.h"

#include "imgui/imgui.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

namespace aker {

	Mesh::Mesh(const std::string& name)
		: name_(name)
	{
		buffer_ = std::make_unique<VertexBuffer>();
	}

	Mesh::Mesh(std::vector<Vertex>& verts, const std::string& name)
		: verts_(verts), name_(name)
	{
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

	void Mesh::Draw(ShaderProgram* shader_program, const Camera& camera)
	{
		shader_program->Bind();
		shader_program->SetUniform("pv", camera.GetMatrix());
		shader_program->SetUniform("materialColor", color_);
		glm::mat4 model_transform{ 1.0f };
		model_transform = glm::translate(model_transform, position_);
		model_transform = glm::scale(model_transform, scale_);
		shader_program->SetUniform("model", model_transform);
		buffer_->Bind();
		glDrawArrays(GL_TRIANGLES, 0, verts_.size());
		buffer_->Unbind();
		shader_program->Unbind();
	}

	void Mesh::ShowDebugMenu() const
	{
		ImGui::Text(name_.c_str());
		// TODO not sure if that is safe
		ImGui::InputText("Name", (char*)name_.c_str(), name_.capacity());
		ImGui::DragFloat3("Position", (float*)glm::value_ptr(position_), 0.01f, -100.0f, 100.0f);
		ImGui::DragFloat3("Scale", (float*)glm::value_ptr(scale_), 0.01f, -100.0f, 100.0f);
		ImGui::DragFloat3("Color", (float*)glm::value_ptr(color_), 0.01f, 0, 1.0f);
	}

}