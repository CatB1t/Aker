#include "GLWindow.h"

#include <cassert>
#include <stdio.h>

#include "glad/gl.h"
#include "glfw/glfw3.h"

namespace aker {
    GLWindow::GLWindow(int width, int height, std::string title)
    : width_(width), height_(height), title_(title), window_(nullptr)
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
        while(!glfwWindowShouldClose(window_))
        {
            // TODO temporary for testing
            glClearColor(1.0, 0.64, 0.0, 1.0);
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(window_);
            glfwPollEvents();
        }
    }

    void GLWindow::ErrorCallback_(int error, const char* desc)
    {
        fprintf(stderr, "GLFW::Error: %s", desc);
    }

    void GLWindow::InitWindow_()
    {
        if(!glfwInit())
        {
            // TODO should terminate
            fprintf(stderr, "GLFW::Error: failed to initalize glfw\n");
        }
        glfwSetErrorCallback(ErrorCallback_);

        SetOpenGLHints_();
        window_ = glfwCreateWindow(width_, height_, title_.c_str(), nullptr, nullptr);
        if(!window_)
        {
            fprintf(stderr, "GLFW::Error: failed to create window %s\n", title_.c_str());
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