#include "GLWindow.h"

#include <cassert>
#include <stdio.h>
#include <format>

#include "glad/gl.h"
#include "glfw/glfw3.h"

#include "renderer/renderer.h"

namespace aker {

    Logger GLWindow::callbackLogger_("GLFW_CALLBACK");

    GLWindow::GLWindow(int width, int height, std::string title)
    : width_(width), height_(height), title_(title), window_(nullptr), logger_(std::format("GLFW({})", title))
    {
        InitWindow_();
    }

    GLWindow::~GLWindow()
    {
        glfwDestroyWindow(window_);
        window_ = nullptr;
        glfwTerminate();
    }

    void GLWindow::Render()
    {
        Renderer renderer;
        renderer.OnStartup();
        while(!glfwWindowShouldClose(window_))
        {
            renderer.Draw();
            glfwSwapBuffers(window_);
            glfwPollEvents();
        }
        renderer.OnEnd();
    }

    void GLWindow::ErrorCallback_(int error, const char* desc)
    {
        callbackLogger_.Error(desc);
    }

    void GLWindow::InitWindow_()
    {
        if(!glfwInit())
        {
            // TODO should terminate
            logger_.Error("Failed to initialize GLFW");
        }
        glfwSetErrorCallback(ErrorCallback_);

        SetOpenGLHints_();
        window_ = glfwCreateWindow(width_, height_, title_.c_str(), nullptr, nullptr);
        if(!window_)
        {
			logger_.Error("Failed to create window");
        }

        glfwMakeContextCurrent(window_);
        gladLoadGL(glfwGetProcAddress);

    }

    void GLWindow::SetOpenGLHints_()
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }

}