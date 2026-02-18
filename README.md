# Ajedrez en C++ | Raylib!

Este es un juego de Ajedrez desarrollado completamente en **c++** utilizando la biblioteca
gráfica **Raylib**. Decidí desarrollar este proyecto como forma de retarme a mi mismo en la aplicación de principios de Programación Orientada a Objetos, gestión de memoria y algoritmos en la lógica del juego.

- ## Recursos utilizados:
  - **Lenguaje:** C++17 (creo)

  - **Gráficos:** [Raylib](https://www.raylib.com/).

  - **Sistema de Construcción:** CMake.

  - **Entorno:** Desarrollado y compilado en Linux.

A fecha de 17/febrero/2025, el juego esta en una etapa MUY temprana y miserable. No hay reglas, no hay nada más que la posibilidad de mover piezas a donde quieras y capturar lo que tu quieras (ni si quiera hay forma de ganar/perder).

- ## Instalación (o eso creo)
Como fue desarrollado en las profundidades de Debian, dudo que funcione en cualquier otro sistema operativo. Lo más probable es que necesites una distro Linux para que no explote (y ni si quiera lo garantizo). Antes de instalarlo (si quieres) asegurate de tener instaladas las dependencias de raylib (en su wiki vienen, como: ```X11```, ```GL```, etc.).

### 1. Clonar el repsitorio

```bash
git clone --recursive --depth 1 https://github.com/IsaacEspinoza07/Ajedrez.git
cd Ajedrez
```
Con ```--recursive``` y ```--depth 1``` te aseguras que te traigas el submódulo de raylib.

Si de casualidad ya lo habias clonado y no ejecutaste el comando anterior puedes usar:

```bash
git submodule update --init --recursive --depth 1
```

Con esto, instalaras el módulo de Raylib listo para usarse :)

### 2. Compilación

Ahora, usaremos CMake para que se haga la magia oscura y se pueda ejecutar el programa:
```bash
mkdir build && cd build

cmake ..

make
```

Y listo!!!

### 3. A Jugar!! (O algo así)
Si no hay una pila ENORME de color rojo diciendo que se borro _root_, entonces todo deberia haber salido bien y haberse creado un ejecutable llamado ```Ajedrez```. Para correrlo, corra:
```bash
./Ajedrez
```

- ## Creditos:
A mi, isaac. Y a mi hermoso perro **Jagger** (husky con conocimientos avanzados de C++). Fue el héroe que debuggeo todo el código y me dictó cómo usar clases, polimorfismos, herencia y memoria dinámica 🙏


