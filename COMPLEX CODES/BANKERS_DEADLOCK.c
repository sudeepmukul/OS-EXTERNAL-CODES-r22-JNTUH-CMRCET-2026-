#include <stdio.h>

int main() {
    int n = 5, r = 3;

    int alloc[5][3] = {
        {0,1,0},
        {2,0,0},
        {3,0,2},
        {2,1,1},
        {0,0,2}
    };

    int max[5][3] = {
        {7,5,3},
        {3,2,2},
        {9,0,2},
        {2,2,2},
        {4,3,3}
    };

    int avail[3] = {3,3,2};

    int need[5][3];
    int finish[5] = {0};
    int safeSeq[5];
    int i, j, k, count = 0;

    // Calculate NEED
    for(i=0;i<n;i++)
        for(j=0;j<r;j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Banker's Algorithm
    while(count < n) {
        int found = 0;

        for(i=0;i<n;i++) {
            if(finish[i] == 0) {

                int flag = 0;
                for(j=0;j<r;j++) {
                    if(need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }

                if(flag == 0) {
                    safeSeq[count++] = i;

                    for(k=0;k<r;k++)
                        avail[k] += alloc[i][k];

                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0) {
            printf("System is NOT SAFE\n");
            return 0;
        }
    }

    printf("SAFE Sequence: ");
    for(i=0;i<n;i++)
        printf("P%d ", safeSeq[i]);

    return 0;
}