#include <stdio.h>

int main()
{
    int pageTable[20];   // Stores frame number for each page
    int n, i;

    int logicalAddr;     // Input logical address
    int pageNo, frameNo; 
    int physicalAddr;    
    int pageSize, offset;

    // Input number of pages
    printf("Enter number of pages: ");
    scanf("%d", &n);

    // Input page size
    printf("Enter page size: ");
    scanf("%d", &pageSize);

    // Input page table (page → frame mapping)
    printf("Enter page table:\n");
    for(i = 0; i < n; i++)
    {
        printf("Page %d -> Frame: ", i);
        scanf("%d", &pageTable[i]);
    }

    // Input logical address
    printf("Enter logical address: ");
    scanf("%d", &logicalAddr);

    // Calculate page number and offset
    pageNo = logicalAddr / pageSize;
    offset = logicalAddr % pageSize;

    // Get frame number from page table
    frameNo = pageTable[pageNo];

    // Calculate physical address
    physicalAddr = (frameNo * pageSize) + offset;

    // Output results
    printf("\nLogical Address: %d\n", logicalAddr);
    printf("Page Number: %d\n", pageNo);
    printf("Offset: %d\n", offset);
    printf("Frame Number: %d\n", frameNo);
    printf("Physical Address: %d\n", physicalAddr);

    return 0;
}