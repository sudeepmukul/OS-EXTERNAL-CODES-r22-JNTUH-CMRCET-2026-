#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd[2];
    char msg[50];
    char buffer[50];
    printf("Enter Message: ");
    fgets(msg,50,stdin);
    pipe(fd);   // create pipe

    if(fork() == 0)
    {
        // Child process
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
    }
    else
    {
        // Parent process
        write(fd[1], msg, sizeof(msg));
    }

    return 0;
}