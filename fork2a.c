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

    a = (int *)malloc(sz * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Enter elements of the array:\n");
    for (i = 0; i < sz; i++) {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
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
