#include "headerfile.h"


int main() {
    pthread_t philosophers[N];
    pthread_mutex_init(&print_mutex, NULL);
    pthread_t server_thread;
    int ids[N];

    // Initialize server
    pthread_mutex_init(&server.mutex, NULL);
    for (int i = 0; i < N; i++) {
        server.chopsticks[i] = 1;
        server.philosopher_requests[i] = 0;
        pthread_cond_init(&server.philosophers[i].condition, NULL);
        server.philosophers[i].id = i;
        last_meal_times[i] = time(NULL); // Initialize last meal times
    }
    // Print starting message
    pthread_mutex_lock(&print_mutex);
    printf("                ==========================================\n");
    printf("                            DINING PHILOSOPHERS            \n");
    printf("                ==========================================\n");
    printf("                       Number of philosophers: %d\n", N);
    printf("                ==========================================\n");
    pthread_mutex_unlock(&print_mutex);

    // Create server thread
    pthread_create(&server_thread, NULL, server_function, NULL);

    // Create philosopher threads
    for (int i = 0; i < N; i++) {
        ids[i] = i;
        eating_times[i] = 0;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    // Join philosopher threads
    for (int i = 0; i < N; i++) {
        pthread_join(philosophers[i], NULL);
    }

    // Join server thread
    pthread_join(server_thread, NULL);

    // Destroy server resources
    pthread_mutex_destroy(&server.mutex);
    pthread_cond_destroy(&server.server_condition);
    for (int i = 0; i < N; i++) {
        pthread_cond_destroy(&server.philosophers[i].condition);
    }
    pthread_mutex_destroy(&print_mutex);

    return 0;
}

void* philosopher(void* num) {
    int id = *(int*)num;

    while (1) {
        think(id);
        request_chopsticks(id);
        eat(id);
        put_down_chopsticks(id);
        pthread_mutex_lock(&print_mutex);
        printf("Philosopher %d is sleeping\n", id+1);
        pthread_mutex_unlock(&print_mutex);
        sleep(sleeping_time) ;

        if (check_starvation(id) == 1) {
            exit(1);
        }
    }
}

void* server_function(void* arg) {
    while (1) {
        pthread_mutex_lock(&server.mutex);

        for (int i = 0; i < N; i++) {
            if (server.philosopher_requests[i] == 1) {
                int left = i;
                int right = (i + 1) % N;

                if (server.chopsticks[left] && server.chopsticks[right]) {
                    server.chopsticks[left] = 0;
                    server.chopsticks[right] = 0;
                    server.philosopher_requests[i] = 0;
                    pthread_cond_signal(&server.philosophers[i].condition);
                }
            }
        }

        pthread_cond_wait(&server.server_condition, &server.mutex);
        pthread_mutex_unlock(&server.mutex);
    }
}

void think(int id) {
    int think_time = rand() % 3 + 1; // Think for a random time between 1 and 3 seconds
    pthread_mutex_lock(&print_mutex);
    printf("Philosopher %d is thinking\n", id+1);
    pthread_mutex_unlock(&print_mutex);
    sleep(think_time);
}

void request_chopsticks(int id) {
    pthread_mutex_lock(&server.mutex);
    server.philosopher_requests[id] = 1;
    pthread_cond_signal(&server.server_condition);

    while (server.philosopher_requests[id] == 1) {
        pthread_cond_wait(&server.philosophers[id].condition, &server.mutex);
    }
    pthread_mutex_unlock(&server.mutex);
}

void eat(int id) {
    int eat_time = rand() % 3 + 1; // Eat for a random time between 1 and 3 seconds
    pthread_mutex_lock(&print_mutex);
    printf("Philosopher %d is eating \n", id+1);
    pthread_mutex_unlock(&print_mutex);
    sleep(eat_time);
    last_meal_times[id] = time(NULL); // Update last meal time

    afficher_nombre_eaten(id);
}

void put_down_chopsticks(int id) {
    pthread_mutex_lock(&server.mutex);
    int left = id;
    int right = (id + 1) % N;

    server.chopsticks[left] = 1;
    server.chopsticks[right] = 1;
    pthread_cond_signal(&server.server_condition);
    pthread_mutex_unlock(&server.mutex);
}

int check_starvation(int id) {
    time_t current_time = time(NULL);
    double elapsed_time = difftime(current_time, last_meal_times[id]);

    if (elapsed_time > max_time_no_eating) {
        pthread_mutex_lock(&print_mutex);
        printf("Philosopher %d has starved.\n", id+1);
        pthread_mutex_unlock(&print_mutex);
        return 1;
    }

    return 0;
}
void afficher_nombre_eaten(int id){
    pthread_mutex_lock(&print_mutex);
    eating_times[id] += 1;
    printf("| ");
    for (int i = 0; i < N; i++){
        printf("%d | ", eating_times[i]);
    }
    printf("\n");
    pthread_mutex_unlock(&print_mutex);
}
