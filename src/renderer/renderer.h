#ifndef _RENDERER_RENDERER_H_
#define _RENDERER_RENDERER_H_

#include <memory>

#include "mesh.h"

namespace aker {
	class Renderer {
	public:
		void OnStartup();
		void Draw();
		void OnEnd();
	private:
		void Clear_();
		std::vector<std::unique_ptr<Mesh>> meshes_;
	};
};

#endif