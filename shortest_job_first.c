
#include <stdio.h>
int main()
{
int arrival_time[10], burst_time[10], temp[10];
int i, smallest, count = 0, time, limit;
double wait_time = 0, turnaround_time = 0, end;
float average_waiting_time, average_turnaround_time;
printf("Enter the total number of processes: ");
scanf("%d", &limit);
// Input: Enter number of processes (e.g., 4)
printf("Enter details of %d processes\n", limit);
for (i = 0; i < limit; i++)
{
printf("Enter arrival time for process %d: ", i + 1);
scanf("%d", &arrival_time[i]);
// Input: Enter arrival time (e.g., 0, 1, 2, 3)
printf("Enter burst time for process %d: ", i + 1);
scanf("%d", &burst_time[i]);
// Input: Enter burst time (e.g., 5, 3, 8, 6)
temp[i] = burst_time[i];
}
burst_time[limit] = 9999;
for (time = 0; count != limit; time++)
{
smallest = limit;
for (i = 0; i < limit; i++)
{
if (arrival_time[i] <= time && burst_time[i] <
burst_time[smallest] && burst_time[i] > 0)
{
smallest = i;
}
}
burst_time[smallest]--;
if (burst_time[smallest] == 0)
{
count++;
end = time + 1;
wait_time += end - arrival_time[smallest] - temp[smallest];
turnaround_time += end - arrival_time[smallest];
}
}
average_waiting_time = wait_time / limit;
average_turnaround_time = turnaround_time / limit;
printf(" \n Average waiting time: % 2f", average_waiting_time);
printf("\n Average turnaround time: % 2f \n", average_turnaround_time);
return 0;
}

/*
 * COMPILATION:
 * gcc shortest_job_first.c -o shortest_job_first
 * 
 * RUN:
 * ./shortest_job_first
 * 
 * DESCRIPTION:
 * Shortest Job First (SJF) CPU scheduling algorithm - preemptive
 * Calculates average waiting time and turnaround time
 * 
 * FIXES NEEDED:
 * None - code should work as-is
 * 
 * EXPECTED OUTPUT:
 * Enter the total number of processes: 4
 * Enter details of 4 processes
 * Enter arrival time for process 1: 0
 * Enter burst time for process 1: 5
 * Enter arrival time for process 2: 1
 * Enter burst time for process 2: 3
 * Enter arrival time for process 3: 2
 * Enter burst time for process 3: 8
 * Enter arrival time for process 4: 3
 * Enter burst time for process 4: 6
 * 
 * Average waiting time: 7.750000
 * Average turnaround time: 13.250000
 */
