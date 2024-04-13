#include "Application.h"

#include <string>
#include <format>

namespace aker {

    Application::Application(std::string name, GLWindow& window)
    : name_(name), window_(window), logger_(std::format("Application({})", name))
    {}

    void Application::Loop()
    {
        logger_.Info("Executing %s loop", name_.c_str());
        window_.Render();
        logger_.Info("%s finished running", name_.c_str());
    }

};