#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#define ARSZ 10

int 
old = ARSZ - 1, 
new = ARSZ - 1, 
rear = 0, numCtr = 0, 
numbersToPrint = 0, 
array[ARSZ] = {0}, 
aveOverNValues = 0, 
maxValues = 0, 
newValue = 0, 
total = 0;

int main(void)
{
    printf("\nEnter the number of values to be averaged over (N): ");
    scanf("%d", &maxValues);
    while (1)
    {
        printf("\nEnter a value: ");
        scanf("%d", &newValue);

        new = (++new) % ARSZ;
        total = total + newValue;
        array[new] = newValue;

        if (numCtr++ < maxValues){
            ++aveOverNValues;
        }else{
            old = (++old) % ARSZ;
            total = total - array[old];
        }
        numbersToPrint = aveOverNValues;
        printf("numbersToPrint = %d\n", numbersToPrint);
        for (int i = 0; i < ARSZ; i++)
            printf("%s%d", " ", array[i]);
        printf("\n%s %d %s %d %s %.2lf", 
        "Number of values entered: ", numCtr,
        "Average over: ", numbersToPrint, 
        "Average: ", ((float)total/aveOverNValues));
    }
}