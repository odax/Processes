// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?
//intial commit change

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int x = 100;
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("This is child %d; x is %d\n", getpid(), x);
        x++;
        printf("child again; x is now %d\n", x);
    } else {
    printf("This is parent %d; x is %d\n", getpid(), x);
    x--;
    printf("parent again; x is now %d\n",x);
    }

    return 0;
}
