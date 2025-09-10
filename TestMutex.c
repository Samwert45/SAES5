#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;

void* ma_fonction_thread(void *arg);

int main(void) {
    int i;
    pthread_t thread[10];
    srand(time(NULL));

    for (i = 0; i < 10; i++) {
        pthread_create(&thread[i], NULL, ma_fonction_thread, (void *)(long)i);
    }

    for (i = 0; i < 10; i++) {
        pthread_join(thread[i], NULL);
    }
    return 0;
}

void* ma_fonction_thread(void *arg) {
    int num_thread = (int)(long)arg; // Conversion correcte de void* en int
    int nombre_iterations, i, n;

    nombre_iterations = rand() % 8;

    for (i = 0; i < nombre_iterations; i++) {
        n = rand() % 10000;
        pthread_mutex_lock(&my_mutex);
        printf("Le thread numéro %d commence son calcul\n", num_thread);
        sleep(2);
        printf("Le thread numéro %d a fini son calcul\n", num_thread);
        pthread_mutex_unlock(&my_mutex);
    }

    pthread_exit(NULL);
}

