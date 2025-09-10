#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main( int argc, char *argv[]){

	pid_t pid;

	char *path = argv[1];
	char *parametre = argv[2];

	pid = fork();

	if(pid == -1){
	perror("fork");
		return 0;
	}

if(pid == 0){

	printf("Salut je suis le fils !");
	return 0;

} else {

	execlp( path, path ,parametre, NULL);

}
wait(NULL);
return 0;

}

