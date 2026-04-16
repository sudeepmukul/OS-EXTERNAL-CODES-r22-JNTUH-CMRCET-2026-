#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int f1, f2, n;
    char buf[100];

    f1 = open(argv[1], O_RDONLY);
    f2 = open(argv[2], O_CREAT | O_WRONLY, 0644);

    while((n = read(f1, buf, 100)) > 0)
    {
        write(f2, buf, n);
    }

    close(f1);
    close(f2);

    printf("Copied Successfully\n");

    return 0;
}



