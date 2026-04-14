#include <stdio.h>

int main()
{
    int n, i;
    int bt[10], rem_bt[10], wt[10], tat[10];
    int t, time = 0;
    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input burst times
    for(i = 0; i < n; i++)
    {
        printf("Enter Burst Time for P%d: ", i+1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i]; // copy
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &t);

    // Round Robin logic
    int done;
    do
    {
        done = 1;

        for(i = 0; i < n; i++)
        {
            if(rem_bt[i] > 0)
            {
                done = 0;

                if(rem_bt[i] > t)
                {
                    time += t;
                    rem_bt[i] -= t;
                }
                else
                {
                    time += rem_bt[i];
                    tat[i] = time;
                    rem_bt[i] = 0;
                }
            }
        }

    } while(done == 0);

    // Calculate WT
    for(i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Output
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", total_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat/n);

    return 0;
}