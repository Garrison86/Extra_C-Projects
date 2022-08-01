#include <stdio.h>
#include <stdlib.h>

#define MAX_ALPHA 26

typedef struct
{
    unsigned int posi;
    unsigned int freq;
} FreqRecord;

int compare(const void *p1, const void *p2);

int main(void)
{

    int charFreq[MAX_ALPHA] = {1, 16, 4, 0, 5, 13, 9, 7, 13, 4, 8, 0, 7, 1, 12, 0, 0, 16, 2, 14, 20, 0, 2, 25, 1};
    int *alphaSort[MAX_ALPHA] = {'\0'};
    
    
    FreqRecord fr[25];
    
    for (int i = 0; i < MAX_ALPHA; i++){
        fr[i].posi = i;
        fr[i].freq = charFreq[i];
    };

    qsort(fr, MAX_ALPHA, sizeof(FreqRecord), compare);
    
    
    for (int i = 0; i < MAX_ALPHA; i++){
        printf("position: %u\tfrequency: %u", fr[i].posi, fr[i].freq);
        alphaSort[i] = &charFreq[fr[i].posi];
        printf("\tthe Letter is %c\n", 66 + fr[i].posi - 1);
        // 65 is the ASCII for 'A'
        // 65 + (0 to 25), is iteration through the alphabit 'A'to'Z' 
    }
}

int compare(const void *p1, const void *p2)
{
    FreqRecord *a = (FreqRecord *)p1;
    FreqRecord *b = (FreqRecord *)p2;
    return (b->freq - a->freq);
}
