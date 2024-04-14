#ifndef GL_WINDOW_H_
#define GL_WINDOW_H_

#include <string>

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include "utils/Logger.h"

namespace aker {

    class GLWindow {
    public:
        GLWindow(int width, int height, std::string title);
        void Render();
        ~GLWindow();

        int GetWidth() const { return width_; };
        int GetHeight() const { return height_; };
        std::string GetTitle() const { return title_; };

    private:
        static void ErrorCallback_(int error, const char* desc);
        static Logger callbackLogger_;

        void InitWindow_();
        void SetOpenGLHints_();

        int width_;
        int height_;
        std::string title_;
        GLFWwindow* window_;
        Logger logger_;
    };

};

#endif