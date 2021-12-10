#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <math.h>



int main(int argc, char *argv[]){
   struct rusage r_usage;

   if (argc != 2) {
      puts("wrong num of args");
      exit(1);
   }
   int SIZE = (int) floor(cbrt(atoi(argv[1])));
   int *p = 0;
   int i = 0;
   int** arr[SIZE];
   int ret = getrusage(RUSAGE_SELF,&r_usage);
   long prev = r_usage.ru_maxrss;
   printf("SIZE %d\n", SIZE);

   printf("memmory usage %ld\n", r_usage.ru_maxrss);

   while (r_usage.ru_maxrss < atoi(argv[1]) + prev) {
      arr[i++] = (int**) calloc(sizeof(int), SIZE*SIZE);
      int ret = getrusage(RUSAGE_SELF,&r_usage);
      printf("memmory usage %ld\n", r_usage.ru_maxrss);
   }

   while (i-- > 0) {
      free(arr[i]);
   }
   
   return 0;
}