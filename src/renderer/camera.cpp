#include "camera.h"

#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "glfw/glfw3.h"

namespace aker {

	Camera::Camera()
		:
		position(0.0f),
		lookAtTarget(0.0f),
		kUp_(0.0f, 1.0f, 0.0f)
	{
	}

	Camera::~Camera()
	{
	}

	void Camera::SetWidthHeight(int width, int height)
	{
		width_ = width;
		height_ = height;
	}

	void Camera::Rotate()
	{
		float angle = glm::radians(glfwGetTime() * speed);
		position = glm::vec3(glm::sin(angle) * radius, height, glm::cos(angle) * radius);
	}

	glm::mat4 Camera::GetView() const
	{
		return glm::lookAt(position, lookAtTarget, kUp_);
	}

	glm::mat4 Camera::GetProjection() const
	{
		return glm::perspective(glm::radians(fov), (float)width_ / (float)height_, 0.1f, 100.0f);
	}

	glm::mat4 Camera::GetMatrix() const
	{
		return GetProjection() * GetView();
	}
}
