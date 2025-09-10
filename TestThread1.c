#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void *ma_fonction_thread(void *argum) {
    int nbsec = *(int*)argum; // Déférencement correct
    printf("Je suis un thread et j'attends %d secondes\n", nbsec);
    sleep(nbsec);
    printf("Je suis un thread et je me termine\n");
    pthread_exit(NULL); // Termine le thread proprement
}

int main(void) {
    int ret;
    pthread_t my_thread;
    int nbsec;
    time_t t1;

    srand(time(NULL));
    t1 = time(NULL);
    nbsec = rand() % 10; // On attend entre 0 et 9 secondes

    // On crée le thread
    ret = pthread_create(&my_thread, NULL, ma_fonction_thread, &nbsec);
    if (ret != 0) {
        fprintf(stderr, "Erreur de creation de thread\n");
        exit(1);
    }

    pthread_join(my_thread, NULL); // On attend la fin du thread
    printf("Dans le main, nbsec = %d\n", nbsec);
    printf("Duree de l'operation = %ld secondes\n", time(NULL) - t1);

    return 0;
}

