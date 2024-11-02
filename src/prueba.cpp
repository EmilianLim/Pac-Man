#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/terminal.hpp>
#include <iostream>
#include <thread>
using namespace std;
using namespace ftxui;
int main(int argc, char const *argv[])
{
    std::string reset_position;
    int frame = 0;
    auto can = Canvas(20,20);


    while (true)
    {    can.DrawPointCircle(9,9,5);
        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
        Element personaje = spinner(21, frame);
        Element lienzo = bgcolor(Color::Yellow, canvas(&can));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);
        this_thread::sleep_for(0.15s);
        frame++;
    }
    return 0;
}