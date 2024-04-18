#include "renderer.h"

#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_glfw.h"
#include "imgui/backends/imgui_impl_opengl3.h"

#include "glad/gl.h"
#include "primitive/square.h"

namespace aker {
	void Renderer::OnStartup()
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		// TODO for testing
		meshes_.push_back(std::make_unique<Square>());
	}

	void Renderer::Clear_()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Renderer::UpdateCamera_()
	{
		camera_.SetWidthHeight(width_, height_);
		camera_.Rotate();
	}

	void Renderer::Draw()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		ImGui::ShowDemoWindow();
		ImGui::Render();

		Clear_();
		UpdateCamera_();
		for (auto& mesh : meshes_)
			mesh->Draw(camera_);

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
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