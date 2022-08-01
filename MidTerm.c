/*******************************************************************************
   #include statements
*******************************************************************************/
#include <stdio.h>
#include <string.h>
/*******************************************************************************
   #define statements
*******************************************************************************/
#define MAXLEN 80

/*******************************************************************************
  type definiton of a structure
*******************************************************************************/
typedef struct {
                unsigned int vowelCount; // number of a e i o u
                unsigned int digitsCount; // number of 8 2 3 4
               } StringStats;

/*******************************************************************************
  forward declarations
*******************************************************************************/

void printStats(char myString[], StringStats s);
StringStats getLetterStats(char myString[],StringStats stats);
StringStats countNumbers(char myString[],StringStats stats);
/*******************************************************************************
  main()  // SHOULD NOT NEED TO BE ALTERED, EXCEPT POSS. FOR ADDING VARIABLES
*******************************************************************************/

int main()
{
    char analysisString[MAXLEN]={'\0'};
    StringStats static stats;

    // The following code segment is to get the analysisString from user
    printf("Input a String and press <return>:");
    char c;
    int i=0;
    scanf("%c",&c);

    while (c != '\n'){
        analysisString[i++]=c;
        scanf("%c",&c);
    };

    analysisString[i]='\0';

    stats = countNumbers(analysisString, stats);
    stats = getLetterStats(analysisString, stats);

    printStats(analysisString,stats);

}
// =================================================================
StringStats getLetterStats(char inString[], StringStats s){
    for (int i = 0; i < MAXLEN; i++)
    {
        if (inString[i] == 'a')
            s.vowelCount++;
        if (inString[i] == 'e')
            s.vowelCount++;
        if (inString[i] == 'i')
            s.vowelCount++;
        if (inString[i] == 'o')
            s.vowelCount++;
        if (inString[i] == 'u')
            s.vowelCount++;
    }
    return s;
}



StringStats countNumbers(char myString[],StringStats n)
{
    n.digitsCount=0;
    for (int i = 0; i < MAXLEN; i++)
    {
        if (myString[i] == '8')
            n.digitsCount++;
            if(myString[i] == '2')
            n.digitsCount++;
             if(myString[i] == '3')
            n.digitsCount++;
             if(myString[i] == '4')
            n.digitsCount++;
    }

return n;
}

void printStats(char inString[], StringStats s){
   // Enter your code below to produce the required output (as shown in the Sample Output) using inString and s.
    for (int i = 0; i < MAXLEN; i++){
    printf("%c",inString[i]);
    }
    printf("\n");
    printf ("There are:\n");
    printf("%d Vowels\n", s.vowelCount);
    printf("%d numbers 8 2 3 4\n", s.digitsCount);
    return;
}

//CST8234 is a required course for CST8219