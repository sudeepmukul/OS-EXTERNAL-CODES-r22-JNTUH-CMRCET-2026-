#include <stdio.h>

// Initial values
int mutex = 1;
int full = 0;
int empty = 5;
int x = 0;

void producer() {
    mutex--;
    full++;
    empty--;

    x++;
    printf("Produced item %d\n", x);

    mutex++;
}

void consumer() {
    mutex--;
    full--;
    empty++;

    printf("Consumed item %d\n", x);
    x--;

    mutex++;
}

int main() {
    int choice;

    while(1) {
        printf("\n1. Produce\n2. Consume\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(mutex == 1 && empty > 0)
                    producer();
                else
                    printf("Buffer is FULL!\n");
                break;

            case 2:
                if(mutex == 1 && full > 0)
                    consumer();
                else
                    printf("Buffer is EMPTY!\n");
                break;

            case 3:
                return 0;
        }
    }
}