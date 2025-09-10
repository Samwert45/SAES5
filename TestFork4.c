#include <sys/types.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
int main(void) 
{ 
     // N° du processus créé 
    pid_t pid; 
 
    printf("Fork ici.\n"); 
    // Création et vérification du fork 
    // le père reçoit en retour le PID du fils,     // le fils reçoit 0, 
    //et en cas d’erreur, fork renvoie -1. 
 
    pid = fork();     
    if (pid == -1)     { 
        // Si fork renvoie -1, il y a eu une erreur ! 
         fprintf(stderr, "Erreur de création du fork - %s\n", strerror(errno));         
	 return (1); 
    } 
    printf("\nFork reussi !\n");     
    if (pid == 0) 
    { 
        // La valeur de retour de fork 
        // est 0, ce qui veut dire qu'on est 
        // dans le processus fils 
        printf("Fils : Je suis le fils, mon pid interne est %d.\n", pid); 
	int variable2 = 3; 
            resultat = variable1 + variable2; 
            printf("Processus fils - Résultat de l'addition : %d\n", resultat); 
 
            exit(0); 
 
    } 
    else if (pid > 0) 
    { 
        printf("Processus lancé pid %d\n", pid); 
        printf("Je suis le pere, le pid de mon fils est %d.\n", pid);   
  	resultat = variable1 + variable2; 
        printf("Processus Père - Résultat de l'addition : %d\n", resultat); 
             // Attente de quelques secondes 
             sleep(20);              // On tue le fils 
             kill(pid, SIGTERM); 
    } 
    return(0); 
} 

