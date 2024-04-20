#include "renderer.h"

#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_glfw.h"
#include "imgui/backends/imgui_impl_opengl3.h"

#include "glad/gl.h"
#include "primitive/cube.h"

namespace aker {
	void Renderer::OnStartup()
	{
		glEnable(GL_DEPTH_TEST);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		// TODO for testing
		meshes_.push_back(std::make_unique<Cube>());
		meshes_.push_back(std::make_unique<Cube>());
	}

	void Renderer::Clear_()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::UpdateCamera_()
	{
		camera_.SetWidthHeight(width_, height_);
		camera_.Rotate();
	}

	void Renderer::DebugUINewFrame_()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void Renderer::DebugUIPreSceneRender_()
	{
		ImGui::Render();
	}

	void Renderer::DebugUIPostSceneRender_()
	{
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void Renderer::ShowDebugWindow_()
	{
		ImGui::Begin("Scene Objects");
		for (int i = 0; i < meshes_.size(); ++i)
		{
			ImGui::PushID(i);
			if (ImGui::Selectable(meshes_[i]->GetName().c_str(), (ui_selecetd_mesh_ == i)))
				ui_selecetd_mesh_ = i;
			ImGui::PopID();
		}
		ImGui::End();
		ImGui::Begin("Object properties");
		if(ui_selecetd_mesh_ == -1)
			ImGui::Text("No selected object");
		else {
			meshes_[ui_selecetd_mesh_]->ShowDebugMenu();
			if (ImGui::Button("Delete"))
			{
				meshes_.erase(meshes_.begin() + ui_selecetd_mesh_);
				ui_selecetd_mesh_ = -1;
			}
		}
		ImGui::End();
	}

	void Renderer::Draw()
	{
		DebugUINewFrame_();
		//ImGui::ShowDemoWindow();
		camera_.ShowDebugMenu();
		ShowDebugWindow_();
		DebugUIPreSceneRender_();

		Clear_();
		UpdateCamera_();
		for (auto& mesh : meshes_)
			mesh->Draw(camera_);

		DebugUIPostSceneRender_();
	}

	void Renderer::OnEnd()
	{
	}

	void Renderer::Resize(int width, int height)
	{
		width_ = width;
		height_ = height;
	}

}