#include <stdio.h>

int main()
{
    int n, i;
    int base[10], limit[10];

    // Input number of segments
    printf("Enter number of segments: ");
    scanf("%d", &n);

    // Input base and limit for each segment
    for(i = 0; i < n; i++)
    {
        printf("Enter base address of segment %d: ", i);
        scanf("%d", &base[i]);

        printf("Enter limit (length) of segment %d: ", i);
        scanf("%d", &limit[i]);
    }

    int segNum, offset;

    // Input segment number
    printf("\nEnter segment number: ");
    scanf("%d", &segNum);

    // Input offset
    printf("Enter offset: ");
    scanf("%d", &offset);


    // Check limit condition
    if(offset >= limit[segNum])
    {
        printf("Segmentation Fault! Offset exceeds limit.\n");
    }
    else
    {
        int physicalAddr = base[segNum] + offset;
        printf("Physical Address: %d\n", physicalAddr);
    }

    return 0;
}