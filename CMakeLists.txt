cmake_minimum_required(VERSION 3.10)
project(MiProyecto)

# Añadir la biblioteca FTXUI
find_package(FTXUI REQUIRED)

# Añadir el ejecutable
add_executable(runprueba prueba.cpp)  # Asegúrate de que 'prueba.cpp' sea el archivo que quieres compilar.

# Vincular con la biblioteca FTXUI
target_link_libraries(runprueba ftxui)
