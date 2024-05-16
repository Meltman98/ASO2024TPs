# ASO2024TPs
Trabajo practico de Garcia amado juan manuel
Trabajo practico 3
1) Ejecutar varias veces los códigos escritos en Python: sinhilos.py y conhilos.py
a) ¿Qué se puede notar con respecto al tiempo de ejecución? ¿Es predecible?
     Rta 1a) Despues de haber ejecutado 10 veces cada algoritmo, pude deducir que el tiempo estimado para sinhilos.py es de 5.4 segundos, mientras que conhilos.py tardo 4.08 segundos. Esto se debe a los temporizadores que tiene cada uno, tomando 0.02s para la primera tarea, 1s para la segunda y 4s para la tercera. En el caso de no tener hilos, los procesos se ejecutan en orden predecible, arranca el primero, termina y despues comienza el segundo y asi, en cambio cuando se tienen multiples hilos, los procesos se lanzan a la vez haciendo que el temporizador mas largo sea el que determine el tiempo total de la ejecucion del programa. En este caso para conhilos, es predecible solo por la secuencia de los timers pero sin ellos se volveria impredecible.
b) Comparar con un campañero el tiempo de ejecución. ¿Son iguales?
     Rta 1b) Los tiempos son bastante similares, la primera cifra es siempre la misma, 4 y 5 respectivamente, ahora para el resto de digitos varia un poco dado a que dependen de la velocidad de cada procesador en ejecutar el codigo.
c)Ejecutar el archivo suma_rasta.py unas 10 veces, luego descomentar (borrar el #) las líneas 11,12,19 y 20 guardarlo y ejecutarlo otras 10 veces. ¿Qué pasó? ¿Por qué?
     Rta 1c)Al ejecutar el archivo suma_resta con argumentos 10 veces me dio siempre el mismo resultado, 0, con un tiempo en promedio de 0.024 segundos. Ahora al descomentar la cosa cambia bastante,el tiempo para obtener un resultado pasa a ser de 7.3 segundos en promedio, se lanzan 2 hilos que suman y restan a la vez una cierta cantidad de veces a la misma variable "acumulador", al no haber restricciones o exclusiones, se genera lo que se conoce como race condition, lo cual produce que el resultado final sea totalmente impredecible ya que esta sujeto al tiempo de ejecucion interno y a la velocidad de ejecucion de cada tarea.

2a) Codigo ordenado y decifrado.
