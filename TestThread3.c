#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void ma_fonction_ab(void *arg) {
   int a,b;
   printf("saisire la valeur a");
   scanf("%d",&a);
   printf("saisire la valeur b");
   scanf("%d",&b);
   int *temp = malloc(sizeof(int));
   *temp = a * b; 
   pthread_exit((void*)temp);
}

void ma_fonction_cd(void *arg) {
   int c,d;
   printf("saisire la valeur c");
   scanf("%d",&c);
   printf("saisire la valeur d");
   scanf("%d",&d);
   int *temp = malloc(sizeof(int));
   *temp = c * d;
   pthread_exit((void*)temp);
}

int main(void) {
    pthread_t my_thread1, my_thread2;
    
    int *resultat_cd, *resultat_ab;  
   
    int ret, temp;
    // Créer le thread
    ret = pthread_create(&my_thread1, NULL, (void *)ma_fonction_ab, NULL);
    ret = ret + pthread_create(&my_thread2, NULL, (void *)ma_fonction_cd, NULL);
    if (ret != 0) {
        fprintf(stderr, "Erreur de création de thread\n");
        exit(1);
    }
    pthread_join(my_thread1, (void**)&resultat_ab);
    pthread_join(my_thread2, (void**)&resultat_cd);
    temp = *resultat_ab + *resultat_cd;
    printf("Valeur reçue par le main : %d\n", temp);

   free(resultat_ab);
   free(resultat_cd); // Libérer la mémoire allouée dans le thread
    return 0;
}


