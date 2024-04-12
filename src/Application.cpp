#include "Application.h"

#include <string>

namespace aker {

    Application::Application(std::string name, GLWindow& window)
    : name_(name), window_(window)
    {}

    void Application::Loop()
    {
        printf("Executing %s loop\n", name_.c_str());
        window_.Render();
        printf("%s finished running\n", name_.c_str());
    }

};