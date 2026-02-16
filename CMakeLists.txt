cmake_minimum_required(VERSION 3.10)
project(Ajedrez)

# Ayuda al LSP (Neovim) a encontrar todo
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Configuración de raylib (submódulo)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(external/raylib)

# Buscamos tus archivos fuente en la carpeta raíz
file(GLOB SOURCES "*.cpp")

# CREAR EL EJECUTABLE (Ahora se llama Ajedrez)
add_executable(Ajedrez ${SOURCES})

# Configuración de rutas de inclusión
target_include_directories(Ajedrez PRIVATE . external/raylib/src)

# Enlazamos las librerías necesarias para Linux
target_link_libraries(Ajedrez raylib GL m pthread dl rt X11)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
