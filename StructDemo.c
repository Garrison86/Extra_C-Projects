#include <stdio.h>
#include <stdlib.h>
# define NDEBUG // if this is omitted then the progam will abort at assert();

/*
// struct not set as a pointer.
struct address {
    char Street[20]; //20
    int aptNum; // 4
    char CityAndProv[20]; //20
} addrA; // sizeof(addrA) == 44
*/
//This struct contains pointers and the malloc() will be needed to 
//initalize the variable in the struct.
struct address{
    char *pStreet; // 4
    int aptNum; // 4
    char *pCityAndProv; // 4 
}addr; // sizeof(addrP) == 12

//typedef struct address addr; //needed if addr is ommited after ...} addr; 

int Main(void){

// Get the street name string
char tempSt[30] = {'\0'};
printf("Enter the street name: ");
gets(tempSt); // get the input from the user and store it


// Reserve memory for street name and copy string to it
assert(addr.pStreet = (char *)malloc(strlen(tempSt)+1));
strcpy(addr.pStreet, tempSt);



return 0;
}