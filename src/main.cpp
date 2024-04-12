#include "Application.h"
#include "GLWindow.h"

int main()
{
    aker::GLWindow window(800, 600, "Demo Window");
    aker::Application app (window.GetTitle(), window);
    app.Loop();
}