#ifndef SHELL_PROJECT_HEADERFILE_H
#define SHELL_PROJECT_HEADERFILE_H
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define N 6 // Number of philosophers
#define max_time_no_eating 2 //decrease if you want to test the starvation
#define sleeping_time 2 //increase to make the starvation happen

typedef struct {
    int id; int request; pthread_cond_t condition;
} Philosopher;

typedef struct {
    pthread_mutex_t mutex; pthread_cond_t server_condition;
    int chopsticks[N]; int philosopher_requests[N];
    Philosopher philosophers[N];
} Server;

Server server;
time_t last_meal_times[N];  // Last meal times for philosophers
int eating_times[N];
pthread_mutex_t print_mutex;


// Function prototypes
void* philosopher(void* num);
void* server_function(void* arg);
void think(int id);
void request_chopsticks(int id);

void eat(int id);
void put_down_chopsticks(int id);
int check_starvation(int id);
void afficher_nombre_eaten(int id);

#endif
