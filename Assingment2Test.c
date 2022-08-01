/*
Stefan Djelmo
041038119
July 24th, 2022
Theory Professor: Rama Thavasinadar
Lab Professor: Dave Houtman
Duration: 
This program releases values that is stored in a .h file and you will be given the option to swap a certain character 
and will permanently change it for the duration of the program running.
*/
#include <stdio.h>
#include <stdlib.h>
//#include "041038119.h"
char cipherText[] = {"CR CAAGNCPEGKF GQMCUWGYGN XF EWG APMWCQG BWCMW EYPQRACER EWG MCUWGY KGEEGY CQREGPN DJ"};
#define SIZE_CIPHER (sizeof(cipherText) / sizeof(cipherText[0]))//size of the cipher text divided by 1
#define SIZE 26

typedef struct{
    unsigned int position;//The letters in array 
    unsigned int frequency;//The number of the alphabet in array
}freq;

//Forward Declarartion
void doFrequencyAnalysis(char *pCipherText, int *charFreq);
void sortFrequencyAddress(int *ptrCharFrequency, int *ptrSort);
void displayFrequencyAnalysis(int *ptrSort);
void swap(char *arr, int i, char a, char b);
static int compare(const void *c1, const void *c2);
void swapCipherText(char *text);//takes cipher text to array and swap characters after


char *pCipherText = cipherText;

int alphaSort [SIZE] = {'\0'};
int *ptrAlpha = alphaSort;

int charFreq [SIZE] = {'\0'};
int *ptrFreq = charFreq;

freq num[SIZE];


int main(void){
    while(1){
        doFrequencyAnalysis(pCipherText, ptrFreq);
        sortFrequencyAddress(ptrFreq, ptrAlpha);
        displayFrequencyAnalysis(ptrAlpha);
        swapCipherText(pCipherText);
    }
}


void doFrequencyAnalysis (char *pCipherText, int *charFreq){
    
    int count;
    
    for(int i = 0; i < SIZE; i++){
        
        for(int j = 0; j < SIZE_CIPHER; j++){
            /*
            nested for loop goes through cipher text and increments count variable
            every time it matches with ASCII value
            */
            if(*(pCipherText + j) == (65+i)){ 
                num[i].frequency++;
            }
            *(charFreq + i) = num[i].frequency;// adding to counter
        }
    num[i].position = count;
    count++;
    }
}

void sortFrequencyAddress(int *ptrCharFrequency, int *ptrSort){
    
    qsort(num, SIZE, sizeof(freq), compare);
    
    for(int i = 0; i < SIZE; i++){
        /*
        putting in value of char freq in the num array alphabet
        */
        *(ptrCharFrequency + num[i].position) = num[i].frequency;
        /*
        sending in address of frequency pointer
        */
        ptrSort[i] = ptrCharFrequency[num[i].position];
    }

    printf("\n");
}


//====================================================== Display
void displayFrequencyAnalysis(int *ptrSort){
    int count;

    for(int i = 0; i < SIZE_CIPHER; i++){
        printf("%c", cipherText[i]);
    }

    printf("\n");
    
    for(int j = 0; j < SIZE; j++){
        printf("%c: %u\n", num[j].position +'A', ptrSort[j]);
    }
    printf("\n");
}



//====================================================== Swap
void swap(char *arr, int i, char a, char b){
     if(*(arr + i) == '\0'){
    return;
    } 
    else if(*(arr + i) == a){
        *(arr + i) = b;
    } 
    else if(*(arr + i) == b){
        *(arr + i) = a;
    }
}

/*
This is the function that causes the switching of the character to a certain character
*/
void swapCipherText(char *text){
    char sub;
    char change;
    printf("Enter two char's to substitute: ");
    scanf("%c%c", &sub, &change);

    /*
    loops through the sizeof cypher text
    */
    for(int i = 0; i < SIZE_CIPHER; i++){
        if(*(text + i) == 'A' + i){//if current letter == equalled to letter 'A' (example)
            swap(text, i, sub, change);
        }
    }  
    for(int i=0; i<SIZE; i++){
        num[i].frequency=0;
    }
}

/*
compares two elements which are the two pointers (does not change value passed in function)
*/
static int compare(const void *c1, const void *c2){
    freq *a = (freq *)c1;
    freq *b = (freq *)c2;
    return (b->frequency - a->frequency);
}