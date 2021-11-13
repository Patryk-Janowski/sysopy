#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

long int num_of_forks;

int main()
{
    while (1)
    {
        fork();
        printf("%ld\n", ++num_of_forks);
    }
}
