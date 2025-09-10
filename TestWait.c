#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

 	int main(void)
 	{
  	pid_t pid;      	
	int i, j;
     	double x = 987.654;
     	if ((pid = fork()) == -1)
     	{    	 	 	perror("fork");   	 	 	exit(1);
     	}

 	 	wait(NULL);

 	 	if (pid == 0)
  {  /* Pere (ou processus fils1) */
       	 	 	for (i = 1; i <= 50; i++)
       	 	 	{    	 	 	 	printf("%d\n", i);
 	 	 	 	/* boucle e ralentissement */  	 	          for (j = 0; j < 10000000; j++)
 	 	 	 	 	x*= x ;
       	 	 }
	pid_t pid2 = getpid();
        pid_t ppid2 = getppid();
	printf("Fils %d : pid = %d, ppid = %d\n",pid,pid2,ppid2);       	
	return 0;
     	}
 	 	else
     	{  /* fils (ou processus fils2) */
       	 	 	for (i = 51; i <= 100; i++)
       	 	 	{    	 	 	 	printf("%d\n", i);
 	 	 	 	/* boucle de ralentissement */
           	 	for (j = 0; j < 10000000; j++)
 	 	 	 	 	x*= x ;
       	 	 	}
	pid_t pid2 = getpid();
        pid_t ppid2 = getppid();
        printf("Pere : pid = %d, ppid = %d\n",pid2,ppid2);
       	 	 	return 0;
     	}

     	return 0;
	}
