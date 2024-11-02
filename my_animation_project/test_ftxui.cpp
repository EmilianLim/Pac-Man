#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <thread>
#include <chrono>

using namespace ftxui;

int main() {
    auto screen = ScreenInteractive::FitComponent();
    int frame = 0;

    auto component = Renderer([&frame] {
        return vbox({
            text("Animación en FTXUI") | center,
            text("Frame: " + std::to_string(frame)) | center,
        }) | border;
    });

    screen.Loop(component);  // Loop para interactuar con el componente

    while (true) {
        frame++;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Control de la velocidad de la animación
    }

    return 0;
}
