#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    int shmid;
    char *ptr;

    // Create shared memory
    shmid = shmget(1234, 50, 0666 | IPC_CREAT);

    // Attach shared memory
    ptr = (char *)shmat(shmid, NULL, 0);

    // Write data
    printf("Enter message: ");
    fgets(ptr, 50, stdin);
    // Read data
    printf("Data in shared memory: %s\n", ptr);

    // Detach memory
    shmdt(ptr);

    // Delete shared memory
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}