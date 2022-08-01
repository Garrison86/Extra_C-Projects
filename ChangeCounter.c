#include <stdio.h>
#include <stdlib.h>
#define PRICE_OF_ITEM 2.25

int main (void){ 
   float denoms[] = {0.10, 0.25, 0.25, 1.00, 2.00};
   int numberOfCoins, index = 4;
   float cash, change, denomination;

   printf("Enter cash amount as $.cc ");
   scanf("%f", &cash);
   if (cash < PRICE_OF_ITEM){
      printf("Error: insufficient funds");
      exit (EXIT_SUCCESS);
   }
   change = cash - PRICE_OF_ITEM; 
 printf("The change back from %2.2f is: %2.2f\n", cash, change);

 while ((change >= 0.05)){
    denomination = denoms[index];
    numberOfCoins = (int)(change/denomination);
    if (numberOfCoins > 0) {
       printf("%d X %2.2f\n", numberOfCoins, denomination);
       change = change - numberOfCoins * denomination;
    }
    index = index - 1;
 }
 printf("\n");
 exit (EXIT_SUCCESS);  
}
