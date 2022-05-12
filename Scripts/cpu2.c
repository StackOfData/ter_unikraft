#include <stdlib.h>
#include <stdio.h>

#define SIZE 100
#define LOOP_ITER 100000

void compute(void){
    int array[SIZE][SIZE];

    for (int i=0; i<SIZE; i++)
        for (int j=0; j<SIZE; j++)
            array[i][j] = i + j;
}

int main(void){
    fprintf(stdout, "Start running cpu2 test\n");

    for (int i=0; i<LOOP_ITER; i++)
        compute();

    fprintf(stdout, "End cpu2 test\n");
}