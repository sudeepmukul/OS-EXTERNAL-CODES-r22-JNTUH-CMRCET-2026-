#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msg {
    long type;
    char text[50];
};

int main() {
    int msgid;
    struct msg m;

    // Create message queue
    msgid = msgget(1234, 0666 | IPC_CREAT);

    // Send message
    m.type = 1;
    printf("Enter String to Send");
    fgets(m.text, sizeof(m.text), stdin);    
    msgsnd(msgid, &m, sizeof(m.text), 0);

    // Receive message
    msgrcv(msgid, &m, sizeof(m.text), 1, 0);

    printf("Received Message: %s\n", m.text);

    // Remove queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}