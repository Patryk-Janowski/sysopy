#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int SIZE = 1000000;

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