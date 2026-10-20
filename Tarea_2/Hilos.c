#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *cuenta_descendente(void *arg)
{
    // HILO: de 10,000 a 1
    for (int i = 10000; i >= 1; i--)
        printf("[HILO] %d\n", i);
    return NULL;
}

int main(void)
{
    pthread_t hilo;

    setvbuf(stdout, NULL, _IONBF, 0);

    if (pthread_create(&hilo, NULL, cuenta_descendente, NULL) != 0)
    {
        perror("pthread_create");
        return EXIT_FAILURE;
    }

    // PROCESO PRINCIPAL: de 1 a 10,000
    for (int i = 1; i <= 10000; i++)
        printf("[PRINCIPAL] %d\n", i);

    pthread_join(hilo, NULL);
    return EXIT_SUCCESS;
}