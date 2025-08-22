#pragma once

class InitPosition {
public:
    virtual void begin() = 0; // Método virtual puro para ser implementado por clases hijas

    virtual ~InitPosition() {} // Destructor virtual para manejo correcto de herencia
};