#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    printf("hello world (pid:%d)\n", (int) getpid());
    int myVar = 100;
    int rc = fork(); 
    if (rc < 0) { // fork failed; exit
       fprintf(stderr, "fork failed\n");
       exit(1);
    } else if (rc == 0) { // child (new process)
        printf("hello, I am child (pid:%d)\n", (int) getpid());
	myVar = 20;
    } else { // parent goes down this path (main)
        int rc_wait = wait(NULL);
        printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int) getpid());
	myVar = 30;
    }
    printf("Hello, I am %d, myVar is %d\n", (int) getpid(), myVar );
    return 0;
}
