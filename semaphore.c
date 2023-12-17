#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h>
#include <stdlib.h> 

int shared = 1; 
sem_t s; 

void *f1(void *arg) {
    sem_wait(&s); 
    int x = shared; 
    printf("Thread 1 reads the value of shared as %d\n", x); 
    x += 1; 
    printf("Local updation by the thread 1: %d\n", x); 
    sleep(1); 
    shared = x; 
    printf("The value of the shared variable is %d\n", shared); 
    sem_post(&s);
}

void *f2(void *arg) {
    int y; 
    sem_wait(&s); 
    y = shared; 
    printf("Thread 2 reads the value of shared as %d\n", y); 
    y -= 1;  
    printf("Local updation by the thread 2: %d\n", y); 
    sleep(1); 
    shared = y; 
    printf("The value of the shared variable is %d\n", shared); 
    sem_post(&s);
}

int main() {
    sem_init(&s, 0, 1); 
    pthread_t thread1, thread2; 
    pthread_create(&thread1, NULL, f1, NULL); 
    pthread_create(&thread2, NULL, f2, NULL); 
    pthread_join(thread1, NULL); 
    pthread_join(thread2, NULL); 
    printf("The final value of the shared variable is %d", shared); 
    puts(""); 
    return 0; 
}
