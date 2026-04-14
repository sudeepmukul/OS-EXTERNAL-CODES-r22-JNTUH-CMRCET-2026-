#include <stdio.h>

int main() {
    int blockSize[10], processSize[10];
    int i, j, m, n;
    int allocation[10];

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

    for(i = 0; i < n; i++)
        allocation[i] = -1;

    // Best Fit Logic
    for(i = 0; i < n; i++) {
        int bestIndex = -1;

        for(j = 0; j < m; j++) {
            if(blockSize[j] >= processSize[i]) {
                if(bestIndex == -1 || blockSize[j] < blockSize[bestIndex]) {
                    bestIndex = j;
                }
            }
        }

        if(bestIndex != -1) {
            allocation[i] = bestIndex;
            blockSize[bestIndex] -= processSize[i];
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