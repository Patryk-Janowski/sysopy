#include <stdio.h>
#include <stdlib.h>
int SIZE = 10^6;

void f_static(){
    double s_arr[SIZE];
    char c = getchar();
}

void f_dynamic(){
    double *d_arr =  (double *)calloc(sizeof(double), SIZE);
    char c = getchar();
    free(d_arr);
}


int main(){
    puts("Static Allocation");
    f_static();
    char c = getchar();
    puts("Dynamic Allocation");
    f_dynamic();
    return 0;
}