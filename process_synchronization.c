//Without using  semaphores
//NO SYNCHRONIZATION

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

int i;
sem_t s1, s2;
void *Thread1(){
sem_wait(&s1);
printf("I am first thread\n");
for (i=10;i<20;i++){
printf("%d\n",i);
}
sem_post(&s2);
return NULL;
}

void *Thread2(){
printf("I am second thread\n");
for (i=0;i<10;i++){
printf("%d\n",i);
}
sem_post(&s1);
return NULL;
}

void *Thread3(){
sem_wait(&s2);
printf("I am third thread\n");
for(i=20;i<31;i++){
printf("%d\n",i);
}
return NULL;
}

int main()
{
pthread_t tid,tid2,tid3;

sem_init(&s1,0,0);
sem_init(&s2,0,0);

pthread_create(&tid,NULL,Thread1,(void *)&tid);
pthread_create(&tid2,NULL,Thread2,(void *)&tid2);
pthread_create(&tid3,NULL,Thread3,(void *)&tid3);
pthread_join(tid,NULL);
pthread_join(tid2,NULL);
pthread_join(tid3,NULL);

sem_destroy(&s1);
sem_destroy(&s2);
return 0;
}
