#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *ma_fonction_thread(void *arg) {
    int *resultat;
    printf("Je suis un thread. Veuillez entrer un entier : ");
    scanf("%d", resultat); // Lire la valeur entrée par l'utilisateur
    printf("Je suis un thread et je me termine\n");

    pthread_exit((void*)resultat); // Retourner le résultat
}

int main(void) {
    pthread_t my_thread; // Identifiant du thread
    int *resultat_ptr;   // Pointeur pour stocker la valeur retournée par le thread
    int ret;

    // Créer le thread
    ret = pthread_create(&my_thread, NULL, ma_fonction_thread, NULL);
    if (ret != 0) {
        fprintf(stderr, "Erreur de création de thread\n");
        exit(1);
    }

    // Attendre la fin du thread et récupérer la valeur retournée
    pthread_join(my_thread, (void**)&resultat_ptr);
    printf("Valeur reçue par le main : %d\n", *resultat_ptr);

    free(resultat_ptr); // Libérer la mémoire allouée dans le thread
    return 0;
}

