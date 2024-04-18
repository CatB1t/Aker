#include "renderer.h"

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
		Clear_();
		UpdateCamera_();
		for (auto& mesh : meshes_)
			mesh->Draw(camera_);
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