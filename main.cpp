#include "window.hpp"

int main()
{
    Window * window = new Window();
    window->run_menu();
    delete window;
    window = nullptr;
    return EXIT_SUCCESS;
}