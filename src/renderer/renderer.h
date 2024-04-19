#ifndef _RENDERER_RENDERER_H_
#define _RENDERER_RENDERER_H_

#include <memory>

#include "camera.h"
#include "mesh.h"

namespace aker {
	class Renderer {
	public:
		void OnStartup();
		void Draw();
		void OnEnd();
		void Resize(int width, int height);
	private:
		void Clear_();
		void UpdateCamera_();
		void DebugUINewFrame_();
		void DebugUIPreSceneRender_();
		void DebugUIPostSceneRender_();

		std::vector<std::unique_ptr<Mesh>> meshes_;
		Camera camera_ = Camera();
		int width_;
		int height_;
	};
};

#endif