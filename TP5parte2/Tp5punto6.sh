#!/bin/bash

# Clave de API de weatherapi.com (reemplaza con tu propia clave)
apiKEY="906d3d73052b4325aa9200348242306"

# Solicitar al usuario que ingrese una ciudad
read -p "Ingrese una ciudad para saber su clima actual: " ciudad_ini

# Reemplazar espacios en la ciudad por %20 para la URL
ciudad_ingresada=$(echo "$ciudad_ini" | tr ' ' '%20')

# Construir la URL de la API
url="http://api.weatherapi.com/v1/current.json?key=$apiKEY&q=$ciudad_ingresada&aqi=no"

# Hacer la solicitud GET a la API y guardar la respuesta en un archivo JSON
curl --request GET "$url" > respuesta.json

# Revertir %20 de vuelta a espacios para mostrar en consola
ciudad_ingresada=$(echo "$ciudad_ini" | tr '%20' ' ')

# Verificar si se obtuvo la respuesta correctamente
if [ -s respuesta.json ]; then
    # Conseguir la temperatura actual del JSON usando jq
    clima=$(jq -r '.current.temp_c' respuesta.json)

    # Mostrar el clima actual de la ciudad
    echo "El clima actual de $ciudad_ingresada es: $clima°C"
else
    echo "No se pudo obtener el clima para la ciudad: $ciudad_ingresada."
fi