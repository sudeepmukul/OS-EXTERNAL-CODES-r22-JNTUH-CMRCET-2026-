#include <stdio.h>

int main() {
    int frames[10], pages[50];
    int n, f, i, j, k, pos, farthest;
    int faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames
    for(i = 0; i < f; i++)
        frames[i] = -1;

    for(i = 0; i < n; i++) {
        int found = 0;

        // Check if page exists
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            pos = -1;
            farthest = i + 1;

            // Find optimal page to replace
            for(j = 0; j < f; j++) {
                int nextUse = -1;

                for(k = i + 1; k < n; k++) {
                    if(frames[j] == pages[k]) {
                        nextUse = k;
                        break;
                    }
                }

                // If page not used again → best to replace
                if(nextUse == -1) {
                    pos = j;
                    break;
                }

                // Choose farthest use
                if(nextUse > farthest) {
                    farthest = nextUse;
                    pos = j;
                }
            }

            // If all pages will be used, replace first
            if(pos == -1)
                pos = 0;

            frames[pos] = pages[i];
            faults++;
        }

        // Print frames
        printf("\n");
        for(j = 0; j < f; j++)
            printf("%d\t", frames[j]);

        if(!found)
            printf("PF");
    }

    printf("\nTotal Page Faults = %d", faults);
    return 0;
}