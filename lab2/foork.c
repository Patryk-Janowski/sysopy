#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

FILE *ptr;
char *heap;
int x[] = {1,2,3};

int main(){

    ptr = fopen("./fileopen", "w+");
    FILE *ptr_l = fopen("./fileopen", "w+");
    heap = malloc(10000);
    heap[0] = 'a';
    char *heap_l = malloc(10000);
    heap_l[0] = 'b';
    int x_l[] = {4,5,6};

    pid_t pid = fork();
    pid_t opid = getpid();

    if ( pid < 0 ){
        fprintf(stderr, "Fork Failed");
        return 1;

    } else if ( pid == 0 ){
        int n;
        scanf("%d", &n);
        if ( x[0] == 1){
            puts("can access global arr from child");
        }
        if ( x_l[0] == 4){
            puts("can access local arr from child");
        }
        printf("Pid of child process %d\n", opid);

    } else {
        wait(NULL);
        char c2 = getchar();
        if ( x[0] == 1){
            puts("can access global arr from parent");
        }
        if ( x_l[0] == 4){
            puts("can access local arr from parent");
        }
        printf("Pid of parent process %d %d\n", opid);
    }

    return 0;
}

