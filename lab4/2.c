#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>


int main() {
   struct rusage r_usage;
   int *p = 0;
   while(1) {
      p = (int*)malloc(sizeof(int)*1000);
      int ret = getrusage(RUSAGE_SELF,&r_usage);
      if(ret == 0)
         printf("Memory usage: %ld kilobytes\n",r_usage.ru_maxrss);
      else
         printf("Error in getrusage. errno = %d\n", errno);
      usleep(10);
   }
   return 0;


void f_dynamic(int num){
    double *d_arr =  (double *)calloc(sizeof(double), SIZE);
    char c = getchar();
    free(d_arr);
}


int main(int argc, char *argv[])  {
   struct rusage r_usage;

   if (argc != 2) {
      puts("wrong num of args");
      exit(1);
   }

   p = (int*)malloc(sizeof(int)*1000);
   int ret = getrusage(RUSAGE_SELF,&r_usage);



   while (r_usage.ru_maxrss < argv[1] && ret == 1){

}




}