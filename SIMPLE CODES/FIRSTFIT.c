#include <stdio.h>

int main() {
    int blockSize[10], processSize[10];
    int i, j, m, n;
    int allocation[10];

    // Input
    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter block sizes:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &blockSize[i]);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter process sizes:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &processSize[i]);

    // Initialize allocation to -1 (not allocated)
    for(i = 0; i < n; i++)
        allocation[i] = -1;

    // First Fit Logic
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(blockSize[j] >= processSize[i]) {
                allocation[i] = j; // allocate block j
                blockSize[j] -= processSize[i]; // reduce size
                break; // move to next process
            }
        }
    }

    // Output
    printf("\nProcess No\tProcess Size\tBlock No\n");
    for(i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i+1, processSize[i]);
        if(allocation[i] != -1)
            printf("%d\n", allocation[i]+1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}