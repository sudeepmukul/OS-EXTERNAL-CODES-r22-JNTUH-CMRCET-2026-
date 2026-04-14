#include <stdio.h>

int main()
{
    int n, i;
    int bt[10], wt[10], tat[10];
    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input burst times
    for(i = 0; i < n; i++)
    {
        printf("Enter Burst Time for P%d: ", i);
        scanf("%d", &bt[i]);
    }

    // First process
    wt[0] = 0;
    tat[0] = bt[0];

    // Calculate WT and TAT
    for(i = 1; i < n; i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = wt[i] + bt[i];
    }

    // Calculate totals
    for(i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Output
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\n", i, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", total_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat/n);

    return 0;
}