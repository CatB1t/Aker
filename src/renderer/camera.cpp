#include "camera.h"

#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "glfw/glfw3.h"

#include "imgui.h"

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
		if (autoRotate_)
		{
			// TODO doesn't work properly
			angle = glm::radians(glfwGetTime() * speed);
		}
		position = glm::vec3(glm::sin(angle) * radius, height, glm::cos(angle) * radius);
	}

	void Camera::ShowDebugMenu()
	{
		ImGui::Begin("Camera Properties");
		ImGui::Checkbox("Auto Rotate", &autoRotate_);

		// Disable Speed or Angle depending on if auto rotate is enabled
		if (!autoRotate_) ImGui::BeginDisabled();
		ImGui::SliderFloat("Speed", &speed, 0.0f, 10.0f);
		if (!autoRotate_) ImGui::EndDisabled();
		else ImGui::BeginDisabled();
		ImGui::SliderAngle("Angle", &angle);
		if (autoRotate_) ImGui::EndDisabled();

		ImGui::SliderFloat("FOV", &fov, 1.0f, 145.0f);
		ImGui::SliderFloat("Height", &height, -5.0f, 5.0f);
		ImGui::SliderFloat("Radius", &radius, 1.0f, 10.0f);
		ImGui::End();
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
