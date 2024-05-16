#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define CANTIDAD_INICIAL_HAMBURGUESAS 8
#define NUMBER_OF_THREADS 2

int cantidad_restante_hamburguesas = CANTIDAD_INICIAL_HAMBURGUESAS;
pthread_mutex_t mutex;

void *comer_hamburguesa_mitad(void *tid)
{
    int hilos = (int)(long)tid;
    int hamburguesas_a_comer = CANTIDAD_INICIAL_HAMBURGUESAS / 2;

    pthread_mutex_lock(&mutex);

    // INICIO DE LA ZONA CRÍTICA
    for (int i = 0; i < hamburguesas_a_comer; i++)
    {
        if (cantidad_restante_hamburguesas > 0)
        {
            printf("Comensal %d: Me voy a comer una hamburguesa, hay %d\n", hilos, cantidad_restante_hamburguesas);
            cantidad_restante_hamburguesas--;
        }
    }
    // SALIDA DE LA ZONA CRÍTICA

    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

void *comer_hamburguesa_restantes(void *tid)
{
    int hilos = (int)(long)tid;

    pthread_mutex_lock(&mutex);

    // INICIO DE LA ZONA CRÍTICA
    while (cantidad_restante_hamburguesas > 0)
    {
        printf("Comensal %d: Me voy a comer una hamburguesa, hay %d\n", hilos, cantidad_restante_hamburguesas);
        cantidad_restante_hamburguesas--;
    }
    // SALIDA DE LA ZONA CRÍTICA

    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t threads[NUMBER_OF_THREADS];
    int status;

    pthread_mutex_init(&mutex, NULL);

    // Crear el primer hilo que come la mitad de las hamburguesas
    printf("Creando hilo 0 para comer la mitad de las hamburguesas\n");
    status = pthread_create(&threads[0], NULL, comer_hamburguesa_mitad, (void *)(long)0);
    if (status != 0)
    {
        printf("Error al crear el hilo 0, código de error %d\n", status);
        exit(-1);
    }

    // Esperar a que el primer hilo termine
    pthread_join(threads[0], NULL);

    // Crear el segundo hilo que come el resto de las hamburguesas
    printf("Creando hilo 1 para comer el resto de las hamburguesas\n");
    status = pthread_create(&threads[1], NULL, comer_hamburguesa_restantes, (void *)(long)1);
    if (status != 0)
    {
        printf("Error al crear el hilo 1, código de error %d\n", status);
        exit(-1);
    }

    // Esperar a que el segundo hilo termine
    pthread_join(threads[1], NULL);
    printf("Se terminaron las burgis!");
    pthread_mutex_destroy(&mutex);
    pthread_exit(NULL);
}