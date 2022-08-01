#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXNUM 100

int main(void){
int result;
int times=0;


    for (int i = 0; i < 50 ; i++){ // loop through 50 trials
    printf("Times Output for trial %d is: \n", i);
    printf("Times: %d", times++ );
    srand(time(NULL)); // seed rand() with the time
        for (int j = 0; j < 10; j++){ // generate and OP 10 values
        result = ((double)rand()/RAND_MAX) * MAXNUM;

printf("\t%d", result); // output row of 10 results
}
printf("\n");
}
}