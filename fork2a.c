#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>  
#include <stdio.h>
#include <stdlib.h>    

void asc(int *a, int sz);
void dsc(int *a, int sz);

int main() {
    pid_t pid;
    int *a, sz, i;

    printf("Enter the size of the array:\n");
    scanf("%d", &sz);
    // Input: Enter an integer (e.g., 5)

    a = (int *)malloc(sz * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Enter elements of the array:\n");
    for (i = 0; i < sz; i++) {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
        // Input: Enter integers one by one (e.g., 34, 12, 5, 78, 23)
    }

    pid = fork();

    switch (pid) {
        case -1:
            printf("Error in fork\n");
            exit(-1);

        case 0:
            printf("\nChild process:\n");
            asc(a, sz);
            exit(0);

        default:
            wait(NULL);  
            printf("\nParent process:\n");
            dsc(a, sz);
            exit(0);
    }

    return 0;
}

void asc(int *a, int sz) {
    int i, j, temp;
    for (i = 0; i < sz; i++) {
        for (j = i + 1; j < sz; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("Sorted array in ascending order:\n");
    for (i = 0; i < sz; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void dsc(int *a, int sz) {
    int i, j, temp;
    for (i = 0; i < sz; i++) {
        for (j = i + 1; j < sz; j++) {
            if (a[i] < a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("Sorted array in descending order:\n");
    for (i = 0; i < sz; i++) 
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

/*
 * COMPILATION:
 * gcc fork2a.c -o fork2a
 * 
 * RUN:
 * ./fork2a
 * 
 * DESCRIPTION:
 * Demonstrates process forking - child sorts ascending, parent sorts descending
 * 
 * PLATFORM:
 * Linux/Unix only - uses fork() and wait() system calls
 * Will NOT compile on Windows (needs WSL or Linux)
 * 
 * FIXES NEEDED:
 * None - code should work as-is on Linux
 * 
 * EXPECTED OUTPUT:
 * Enter the size of the array:
 * 5
 * Enter elements of the array:
 * a[0]: 34
 * a[1]: 12
 * a[2]: 5
 * a[3]: 78
 * a[4]: 23
 * 
 * Child process:
 * Sorted array in ascending order:
 * 5    12    23    34    78
 * 
 * Parent process:
 * Sorted array in descending order:
 * 78    34    23    12    5
 */
