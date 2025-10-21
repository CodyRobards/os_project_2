Problem Statement:

We have three (03) threads: Thread 1, Thread 2, and Thread 3:

[1]. Thread 2 having function to print 0 to 9 finishes before Thread 1 having function to print
10 to 19
[2]. Thread 1 finishes before Thread 3 having function to print 20 to 30
[3]. Use semaphore(s) to enforce these synchronization rules by adding P() and V() calls
[4]. You must include sem\_ routine calls such as sem_wait(), sem_post() and sem_init() in
suitable places to create and initialize the semaphores.
[5]. Do not use any synchronization primitives or techniques other than sempahores.

Problem Description / Methodology:

You can work with the given sample source code

Here you need to first add the #include<semaphore.h> header as follows:

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

Next, you need to declare the semaphore variables as follows:

int i; //shared variable
sem_t s1, s2; //semaphore variables

After that, you need to use the sem_wait(); [i.e., P() calls] and sem_post(&s2); [i.e., V() calls]
properly to enforce the synchronization rules to the following three (03) thread functions as per
problem statement mentioned above. I am showing you all for Thread 1. You need to complete for
the Thread 2 and Thread 3.

void \*Thread1(){
sem_wait(&s1); // This is P()
printf("I am first thread\n");
for (i=10;i<20;i++){
printf("%d\n",i);
}
sem_post(&s2); // This is V()
}

void \*Thread2(){
// TO DO BY YOURSELF
printf("I am second thread\n");
for (i=0;i<10;i++){
printf("%d\n",i);
}
}

void \*Thread3(){
// TO DO BY YOURSELF
printf("I am third thread\n");
for(i=20;i<31;i++){
printf("%d\n",i);
}
}
Finally, you need to write the main() method as follows:

int main()
{
sem_init(&s1,0,0);
sem_init(&s2,0,0);

//1st argument for the address of the semaphore variable
//2nd arg for the thread, non-zero value is used in case for process
//3rd arg for initializing the semaphore value

pthread_t tid,tid2,tid3;

pthread_create(&tid,NULL,Thread1,(void _)&tid);
pthread_create(&tid2,NULL,Thread2,(void _)&tid2);
pthread_create(&tid3,NULL,Thread3,(void \*)&tid3);

sem_destroy(&s1);
sem_destroy(&s2);
//for destroying the semaphores

pthread_exit(NULL);
return 0;
}

Note: You can save the entire program as process_synchronization.c file.

For compilation:

$ gcc process_synchronization.c -lpthread -o process_synchronization.out

For execution:

$ ./process_synchronization.out
