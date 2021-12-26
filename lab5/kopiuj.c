#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>


size_t copy(int in, int out, char *buffer, size_t n)
{
    ssize_t t;
    ssize_t bytes = 0;

    while ((t = read(in, buffer, n)) > 0)
    {
        if (write(out, buffer, t) != t)
            return 0;
        bytes += t;
    }

    return bytes;
}


int main(int argc, char* argv[])
{
    if (argc != 4){
        puts("wrong num of args");
        exit(1);
    }
    
    clock_t timing;
    int buffer_size = atoi(argv[1]);
    char *buffer = malloc(sizeof(char) * buffer_size);
    int fp1 = open(argv[2], O_RDONLY);
    int fp2 = open(argv[3], O_WRONLY | O_CREAT, 0644);


    timing = clock();
    size_t copied = copy(fp1, fp2, buffer, buffer_size);
    timing = clock() - timing;

    printf("buffer size = %9d, time : %8ld (copied %zu bytes)\n",
            buffer_size, timing, copied);

    close(fp2);
    free(buffer);
    close(fp1);

    return 0;
}