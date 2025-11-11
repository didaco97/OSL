
#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<time.h>

pthread_mutex_t x,wsem;
pthread_t tid;
int readcount;
void initialize()
{
pthread_mutex_init(&x,NULL);
pthread_mutex_init(&wsem,NULL);
readcount=0;
}
void* reader(void* param)
{
int waittime;
waittime=rand()%5;
printf("\n reader is trying to enter");
pthread_mutex_lock(&x);
readcount++;
if(readcount==1)
pthread_mutex_lock(&wsem);
printf("\n %d reader is inside",readcount);
pthread_mutex_unlock(&x);
sleep (waittime);
pthread_mutex_lock(&x);
readcount++;
if(readcount==0)
{
pthread_mutex_unlock(&wsem);
pthread_mutex_unlock(&x);
printf("\n writer is leaving");
}
}
void* writer(void* param)
{
int waittime;
waittime=rand()%3;
printf("\n writer is trying to enter");
pthread_mutex_lock(&wsem);
printf("\n Writer has entered");
sleep(waittime);
pthread_mutex_unlock(&wsem);
printf("\n writer is leaving");
sleep(30);
exit(0);
}
int main()
{
int n1,n2,i;
printf("\n Enter the number of readers:");
scanf("%d",&n1);
// Input: Enter number of reader threads (e.g., 3)
printf("\n enter the number of writer");
scanf("%d",&n2);
// Input: Enter number of writer threads (e.g., 2)
for(i=0;i<n1;i++)
pthread_create(&tid,NULL,reader,NULL);
for(i=0;i<n1;i++)
pthread_create(&tid,NULL,writer,NULL);
sleep(30);
exit(0);
}

/*
 * COMPILATION:
 * gcc readwrite.c -pthread -o readwrite
 * 
 * RUN:
 * ./readwrite
 * 
 * DESCRIPTION:
 * Reader-Writer problem using pthread mutex
 * 
 * CRITICAL BUG:
 * Line 30 has a bug: "readcount++" should be "readcount--"
 * This will cause incorrect behavior as readers exit
 * 
 * FIX REQUIRED:
 * Change line 30 from:
 *     readcount++;
 * To:
 *     readcount--;
 * 
 * Also note: Line 60 should probably use n2 instead of n1 for writer loop
 * 
 * EXPECTED OUTPUT:
 * Enter the number of readers:3
 * enter the number of writer2
 * 
 * reader is trying to enter
 * 1 reader is inside
 * reader is trying to enter
 * 2 reader is inside
 * reader is trying to enter
 * 3 reader is inside
 * writer is trying to enter
 * writer is trying to enter
 * Writer has entered
 * writer is leaving
 * writer is leaving
 */

