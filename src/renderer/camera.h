#ifndef _RENDERER_CAMERA_H_
#define _RENDERER_CAMERA_H_

#include "glm/glm.hpp"

namespace aker {

	class Camera {
	public:
		Camera();
		~Camera();

		void SetWidthHeight(int width, int height);
		void Rotate();
		void ShowDebugMenu();

		glm::mat4 GetView() const;
		glm::mat4 GetProjection() const;
		glm::mat4 GetMatrix() const;

		glm::vec3 position;
		glm::vec3 lookAtTarget;

		float fov = 60.0f;
		float speed = 10.0f;
		float radius = 5.0f;
		float angle = 0.0f;
		float height = 0.0f;
	private:
		bool autoRotate_ = true;
		int width_ = 0;
		int height_ = 0;
		glm::vec3 kUp_;
	};

}


#endif