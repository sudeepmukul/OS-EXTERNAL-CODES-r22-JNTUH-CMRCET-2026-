#include <stdio.h>

int main() {
    int frames[10], pages[50];
    int time[10];  // to store usage time
    int n, f, i, j, pos, faults = 0, counter = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames
    for(i = 0; i < f; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    for(i = 0; i < n; i++) {
        int found = 0;

        // Check if page is already present
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                counter++;
                time[j] = counter;  // update recent use
                break;
            }
        }

        // If page fault
        if(!found) {
            // Find least recently used page
            pos = 0;
            for(j = 1; j < f; j++) {
                if(time[j] < time[pos])
                    pos = j;
            }

            frames[pos] = pages[i];
            counter++;
            time[pos] = counter;
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