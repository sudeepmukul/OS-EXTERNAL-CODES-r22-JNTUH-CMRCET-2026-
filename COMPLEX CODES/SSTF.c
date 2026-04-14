#include <stdio.h>
#include <stdlib.h>  // for abs()

int main() {
    int n, head, i, j, total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n], visited[n];  // req = disk requests, visited = served or not

    printf("Enter requests:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &req[i]);
        visited[i] = 0;  // initially no request is served
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    // Repeat until all requests are served
    for(i = 0; i < n; i++) {
        int min = 9999, index = -1;

        // Find closest request from current head
        for(j = 0; j < n; j++) {
            if(!visited[j]) {  // check only unvisited requests
                int dist = abs(head - req[j]);  // distance from head

                // pick the minimum distance request
                if(dist < min) {
                    min = dist;
                    index = j;
                }
            }
        }

        visited[index] = 1;      // mark as served

        total += min;            // add seek time
        head = req[index];       // move head to that request
    }

    printf("Total Seek Time = %d\n", total);
    return 0;
}