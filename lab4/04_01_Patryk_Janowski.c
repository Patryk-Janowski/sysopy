#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int SIZE = 1000000;

void f_static(){
    double s_arr[SIZE];
    for (size_t i = 0; i < SIZE; i++){
        s_arr[i] =(double) SIZE;
    }
    {
        /* code */
    }
    
    char c = getchar();
}

void f_dynamic(){
    double *d_arr =  (double *)calloc(sizeof(double), SIZE);
    for (size_t i = 0; i < SIZE; i++){
        d_arr[i] =(double) SIZE;
    }
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