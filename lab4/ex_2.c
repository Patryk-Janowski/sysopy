#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <math.h>

int main(int argc, char *argv[]){

   if (argc != 2) {
      puts("wrong num of args");
      exit(1);
   }

   struct rusage r_usage;
   int SIZE = (int) ceil(cbrt(atoi(argv[1])) / (sizeof(double)));
   double **arr[SIZE];
   int ret = getrusage(RUSAGE_SELF,&r_usage);
   long prev = r_usage.ru_maxrss;
   printf("SIZE %d\n", SIZE);
   printf("memmory usage %ld\n", r_usage.ru_maxrss);
   
   int i = 0;
   while (r_usage.ru_maxrss < atoi(argv[1]) + prev) {
      arr[i++] = (double**) calloc(sizeof(double), SIZE*SIZE);
      ret = getrusage(RUSAGE_SELF,&r_usage);
      if(i % 10 == 0){
         sleep(1);
         printf("memmory usage %ld\n", r_usage.ru_maxrss);
      }
   }

   printf("size of arr %d\n", i);

   while (i-- > 0) {
      free(arr[i]);
   }
   
   return 0;
}