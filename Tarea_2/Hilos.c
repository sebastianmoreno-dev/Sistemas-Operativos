#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *cuenta_ascendente(void *arg)
{
    for (int i = 1; i <= 10000; i++)
        printf("[HILO 1] %d\n", i);
    return NULL;
}

void *cuenta_descendente(void *arg)
{
    for (int i = 10000; i >= 1; i--)
        printf("[HILO 2] %d\n", i);
    return NULL;
}

int main(void)
{
    pthread_t h1, h2;

    setvbuf(stdout, NULL, _IONBF, 0);

    if (pthread_create(&h1, NULL, cuenta_ascendente, NULL) != 0)
    {
        perror("pthread_create h1");
        return EXIT_FAILURE;
    }
    if (pthread_create(&h2, NULL, cuenta_descendente, NULL) != 0)
    {
        perror("pthread_create h2");
        return EXIT_FAILURE;
    }

    pthread_join(h1, NULL);
    pthread_join(h2, NULL);
    return EXIT_SUCCESS;
}