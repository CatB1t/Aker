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
		glm::mat4 model_transform{ 1.0f };
		model_transform = glm::translate(model_transform, position_);
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
	}

}