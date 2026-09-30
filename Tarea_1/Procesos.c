#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return EXIT_FAILURE;
    }

    if (pid == 0)
    {
        // HIJO: de 10,000 a 1
        for (int i = 10000; i >= 1; i--)
            printf("[HIJO  %d] %d\n", getpid(), i);
        exit(EXIT_SUCCESS);
    }
    else
    {
        // PADRE: de 1 a 10,000
        for (int i = 1; i <= 10000; i++)
            printf("[PADRE %d] %d\n", getpid(), i);
        wait(NULL);
    }
    return EXIT_SUCCESS;
}