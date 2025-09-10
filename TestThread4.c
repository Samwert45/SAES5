#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *ma_fonction_thread(void *arg) {
    int *resultat;
    *resultat = 1; // Lire la valeur entrée par l'utilisateu
    pthread_exit((void*)resultat); // Retourner le résultat
}

int main(void) {
    pthread_t A0, A1, A2, A3, A4, A5, A6, A7; // Identifiant du thread
    int *resultat_ptr;   // Pointeur pour stocker la valeur retournée par le thread
    int ret,ret2,ret3,ret4,ret5,ret6,ret7,ret8;

    // Créer le thread
    ret = pthread_create(&A0, NULL, ma_fonction_thread, NULL);
    if (ret != 0) {
        fprintf(stderr, "Erreur de création de thread\n");
        exit(1);
    }
    printf("A0 est fini");
    // Attendre la fin du thread et récupérer la valeur retournée
    pthread_join(A0, (void **)&resultat_ptr);
    ret2 = pthread_create(&A1, NULL, ma_fonction_thread, NULL);
    ret3 = pthread_create(&A2, NULL, ma_fonction_thread, NULL);
    ret4 = pthread_create(&A3, NULL, ma_fonction_thread, NULL);

    if (ret2 == 0){
    pthread_join(A1, (void**)&resultat_ptr);
    printf("A1 est fini\n");
    ret5 = pthread_create(&A4, NULL, ma_fonction_thread, NULL);
    ret6 =  pthread_create(&A5, NULL, ma_fonction_thread, NULL);
    }
    if (ret3 == 0) {
    pthread_join(A2, (void**)&resultat_ptr);
    printf("A2 est fini\n");
    ret7 = pthread_create(&A6, NULL, ma_fonction_thread, NULL);
    }
    pthread_join(A4, (void**)&resultat_ptr);
    printf("A4 est fini\n");
    pthread_join(A5, (void**)&resultat_ptr);
    printf("A5 est fini\n");
    pthread_join(A6, (void**)&resultat_ptr);
    printf("A6 est fini\n");
    pthread_join(A3, (void**)&resultat_ptr);
    printf("A3 est fini\n");
    ret8 = pthread_create(&A7, NULL, ma_fonction_thread, NULL);
    pthread_join(A7, (void**)&resultat_ptr);
    printf("A7 est fini\n");
    return 0;
}
