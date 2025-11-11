#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
int n, i, j, head, total = 0;
int requests[100], visited[100] = {0};
printf("Enter number of disk requests: ");
scanf("%d", &n);
// Input: Enter number of disk requests (e.g., 8)
printf("Enter disk requests: ");
// Input: Enter disk request positions separated by spaces (e.g., 98 183 37 122 14 124 65 67)
for (i = 0; i < n; i++)
scanf("%d", &requests[i]);
printf("Enter initial head position: ");
scanf("%d", &head);
// Input: Enter initial disk head position (e.g., 53)
printf("\nSSTF Disk Scheduling:\n");
printf("Sequence: %d", head);
int count = 0;
while (count < n) {
int min = 9999, index = -1;
// Find the request closest to current head
for (i = 0; i < n; i++) {
if (!visited[i]) {
int dist = abs(head - requests[i]);
if (dist < min) {
min = dist;
index = i;
}
}
}
// Move head to that request
total += min;
head = requests[index];
visited[index] = 1;
count++;
printf(" -> %d", head);
}
printf("\nTotal head movement: %d\n", total);
return 0;
}

/*
 * COMPILATION:
 * gcc sstf.c -o sstf
 * 
 * RUN:
 * ./sstf
 * 
 * DESCRIPTION:
 * SSTF (Shortest Seek Time First) disk scheduling algorithm
 * Calculates total head movement for disk scheduling
 * 
 * FIXES NEEDED:
 * None - code should work as-is
 * 
 * EXPECTED OUTPUT:
 * Enter number of disk requests: 8
 * Enter disk requests: 98 183 37 122 14 124 65 67
 * Enter initial head position: 53
 * 
 * SSTF Disk Scheduling:
 * Sequence: 53 -> 65 -> 67 -> 37 -> 14 -> 98 -> 122 -> 124 -> 183
 * Total head movement: 236
 */

