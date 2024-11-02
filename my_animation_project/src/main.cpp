#include <ftxui/component/component.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/util/ref.hpp>
#include <thread>
#include <chrono>

using namespace ftxui;

int main() {
    // Crear una pantalla interactiva
    auto screen = ScreenInteractive::TerminalOutput();
    
    // Animación de una cara parpadeando
    bool eye_state = true;  // Estado de los ojos: verdadero (abiertos) o falso (cerrados)
    
    // Crear un componente que muestra una cara
    auto renderer = Renderer([&]() {
        return vbox({
            text(eye_state ? "    O   O    " : "    -   -    ") | center,  // Ojos
            text("      |      ") | center,  // Boca
            text("   (     )   ") | center,  // Cara
            separator(),
            text("Presiona 'q' para salir.") | center  // Instrucción
        });
    });

    // Asignar el bucle principal al renderer
    screen.Loop([&]() {
        renderer->Render();  // Renderizar la cara
        eye_state = !eye_state;  // Cambiar el estado de los ojos
        std::this_thread::sleep_for(std::chrono::milliseconds(500));  // Esperar 500 ms
        return renderer;  // Devolver el renderer
    });
    
    return 0;
}
