#include <stdio.h>

int main() {
    int n = 5, r = 3;
    int i, j, k, count = 0;
    int process;

    int alloc[5][3], max[5][3], need[5][3];
    int avail[3], request[3];
    int finish[5] = {0}, safeSeq[5];

    // Input Allocation Matrix
    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);

    // Input Max Matrix
    printf("Enter Max Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

    // Input Available Resources
    printf("Enter Available Resources:\n");
    for(i = 0; i < r; i++)
        scanf("%d", &avail[i]);

    // Calculate Need Matrix
    for(i = 0; i < n; i++)
        for(j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Input Request
    printf("Enter Process Number: ");
    scanf("%d", &process);

    printf("Enter Request:\n");
    for(i = 0; i < r; i++)
        scanf("%d", &request[i]);

    // Check Request <= Need and Available
    for(i = 0; i < r; i++) {
        if(request[i] > need[process][i]) {
            printf("Exceeded Maximum Need\n");
            return 0;
        }
        if(request[i] > avail[i]) {
            printf("Resources Not Available\n");
            return 0;
        }
    }

    // Temporary Allocation
    for(i = 0; i < r; i++) {
        avail[i] -= request[i];
        alloc[process][i] += request[i];
        need[process][i] -= request[i];
    }

    // Safety Check
    while(count < n) {
        int found = 0;

        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {
                int flag = 0;

                for(j = 0; j < r; j++) {
                    if(need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }

                if(flag == 0) {
                    safeSeq[count++] = i;

                    for(k = 0; k < r; k++)
                        avail[k] += alloc[i][k];

                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0) {
            printf("System Not Safe\n");
            return 0;
        }
    }

    printf("Request Granted\nSafe Sequence: ");
    for(i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);

    return 0;
}