#ifndef _RENDERER_LIGHT_H_
#define _RENDERER_LIGHT_H_

#include "glm/glm.hpp"

namespace aker {
	// TODO refactor as a base class
	// For directional, point and spotlight
	class Light
	{
	public:
		Light(const glm::vec3 position, const glm::vec3 color);
		~Light() = default;

	private:
		glm::vec3 position_;
		glm::vec3 color_;
	};
}

#endif