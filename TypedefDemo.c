#include <stdio.h> 
#include <string.h>

//typedef char user[25];

// in a typedef struct the variable name of the struct 
// goes after the closing curly bracket. e.g. ...} User;
typedef struct { 
   char name[25];
   char password[12];
   int id;
} User;

typedef struct deptartment {
char deptName[30];
char campus[14];
int phoneNumber;
} dept;

// pointer structs or variables in the struck that are
// pointers, need an amount of memory to be allocated to
// them before they can be used.
// ex. myAdd
typedef struct typeAddress {
char *pStreet;
int aptNum;
char *pCityAndProv;
} addr;

// in a normal struct, the variable struct name goes 
// before the opening curly bracket eg. struct address{...
struct address{
   char *pStreet;
   int aptNum;
   char *pCityAndProv;
};



int main() 
{
   // typedef = reserved keyword that gives an existing datatype a "nickname"

   User user1 = {"Bro", "password123", 123456789};
   User user2 = {"Bruh", "password321", 987654321};
 
   printf("%s\n", user1.name);
   printf("%s\n", user1.password);
   printf("%d\n", user1.id);
   printf("\n");
   printf("%s\n", user2.name);
   printf("%s\n", user2.password);
   printf("%d\n", user2.id);

   return 0; 
}
