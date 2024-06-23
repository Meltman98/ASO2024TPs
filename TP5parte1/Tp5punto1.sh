#!/bin/bash

# Función para generar un número aleatorio entre 1 y 100
generar_numero_aleatorio() {
    echo $((RANDOM % 100 + 1))
}

# Función para el juego de adivinanza
jugar_adivinanza() {
    local numero_secreto=$(generar_numero_aleatorio)
    local intento
    local adivinado=0

    echo "¡Bienvenido al juego de adivinanza!"
    echo "He generado un número aleatorio entre 1 y 100."
    echo "¡Intenta adivinarlo!"

    while [ $adivinado -eq 0 ]; do
        echo -n "Introduce tu intento: "
        read intento

        if [ $intento -lt $numero_secreto ]; then
            echo "Demasiado bajo. Intenta de nuevo."
        elif [ $intento -gt $numero_secreto ]; then
            echo "Demasiado alto. Intenta de nuevo."
        else
            echo "¡Felicidades! Has adivinado el número."
            adivinado=1
        fi
    done
}

# Iniciar el juego
jugar_adivinanza
