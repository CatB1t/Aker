#include "renderer.h"

#include "glad/gl.h"

namespace aker {
	void Renderer::OnStartup()
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		// TODO for testing
		std::vector<Vertex> verts = {
			{-0.5f, -0.5f, 0.0f},
			{0.5f, -0.5f, 0.0f},
			{0.0f,  0.5f, 0.0f}
		};

		meshes_.push_back(std::make_unique<Mesh>(verts));
	}

	void Renderer::Clear_()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Renderer::Draw()
	{
		Clear_();
		for (auto& mesh : meshes_)
			mesh->Draw();
	}

	void Renderer::OnEnd()
	{
	}

}