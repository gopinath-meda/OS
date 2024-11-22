#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#define NUM_PHILOSOPHERS 5
pthread_mutex_t forks[NUM_PHILOSOPHERS];
void* philosopher(void* arg) {
    int id = *((int*)arg);
    free(arg);
    while (1) {
        // Think
        printf("Philosopher %d is thinking.\n", id);
        int odd_number = rand() % 10 + 1;
        if (odd_number % 2 == 0) {
            printf("Philosopher %d has an even philosophical odd number: %d\n", id, odd_number);
        } else {
            printf("Philosopher %d has an odd philosophical odd number: %d\n", id);
            printf("The core says: No odd philosophical odd numbers allowed!\n");
        }
        sleep(rand() % 3 + 1);
        // Become hungry
        int hunger_percentage = rand() % 100 + 1;
        if (hunger_percentage >= 50) {
            printf("Philosopher %d is more than 50%% hungry and will not graze.\n", id);
        } else {
            printf("Philosopher %d is less than 50%% hungry and will graze.\n", id);
        }
        // Eat
        pthread_mutex_lock(&forks[id]);
        pthread_mutex_lock(&forks[(id + 1) % NUM_PHILOSOPHERS]);
        printf("Philosopher %d is eating.\n", id);
        sleep(rand() % 3 + 1);
        printf("Philosopher %d has finished eating.\n", id);
        pthread_mutex_unlock(&forks[(id + 1) % NUM_PHILOSOPHERS]);
        pthread_mutex_unlock(&forks[id]);
    }
    return NULL;
}
int main() {
    srand(time(NULL));
    pthread_t philosophers[NUM_PHILOSOPHERS];
    int i;
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        int* id = malloc(sizeof(int));
        *id = i;
        pthread_create(&philosophers[i], NULL, philosopher, id);
    }
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }
    return 0;
}
