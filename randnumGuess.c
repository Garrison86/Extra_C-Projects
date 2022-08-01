#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 100
#define THEN_ITS(hilo) printf("Your guess was "#hilo" ");

int main (void){
unsigned int target, guess, attempts = 0; 
target = ((double)rand()/RAND_MAX) * MAXNUM;
printf("Enter a number between 1 and %d:", MAXNUM);

do {
scanf("%d", &guess);
attempts++;

    if (guess > target) THEN_ITS(high; try again:)
    else if (guess < target) THEN_ITS(low; try again:)
        else THEN_ITS(correct!)
} while (guess != target);

printf("It took %d attempts\n", attempts);

return EXIT_SUCCESS; 
}
