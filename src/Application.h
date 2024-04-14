#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <string>

#include "GLWindow.h"
#include "utils/Logger.h"

namespace aker {
    class Application 
    {
    public:
        Application(std::string name, GLWindow& window);
        void Loop();

    private:
        std::string name_ = "Unnamed";
        GLWindow& window_;
        Logger logger_;
    };
}

#endif