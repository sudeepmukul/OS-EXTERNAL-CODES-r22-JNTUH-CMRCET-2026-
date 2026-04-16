#include <stdio.h>
#include <stdlib.h>

int main()
{
    int req[20], n, head, size;
    int i, j, temp, total = 0, firstHead;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue: ");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &size);

    firstHead = head;   // store original head

    // Sort requests
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(req[i] > req[j])
            {
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    // Move right side
    for(i = 0; i < n; i++)
    {
        if(req[i] >= head)
        {
            total += abs(req[i] - head);
            head = req[i];
        }
    }

    // Go to end
    total += abs((size - 1) - head);

    // Jump to start
    total += (size - 1);
    head = 0;

    // Continue right again
    for(i = 0; i < n; i++)
    {
        if(req[i] < firstHead)
        {
            total += abs(req[i] - head);
            head = req[i];
        }
    }

    printf("Total Seek Time = %d\n", total);

    return 0;
}