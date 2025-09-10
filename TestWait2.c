#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

	pid_t pid;

	setenv("MY_VAR1","Hello",1); //Definition de la variable MY_VAR1
        setenv("MY_VAR2","World",1);
        char *my_var1 = getenv("MY_VAR1");
        char *my_var2 = getenv("MY_VAR2");

	
	pid = fork();
	

	if (pid == -1){
	
	perror("fork");
	exit(1);
} 

if (pid == 0) {
       
        //ici on est dans le fils
        printf("Le fils (PID : %d)\n", getpid());
        printf("Valeur de MY_VAR1 : %s\n", my_var1);
        printf("Valeur de MY_VAR2 : %s\n", my_var2);  


}

wait(NULL);

return 0;
}

