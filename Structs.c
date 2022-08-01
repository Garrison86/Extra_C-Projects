#include <stdio.h>
#include <string.h>


//==Used=for=example=1=====
struct Player
{
   char name[12];
   int score;
};

//==Used=for=example=2=====
struct Student
{
   char name[12];
   float gpa;
};

int main()
{
   // struct = collection of related members ("variables") 
   //          they can be of different data types
   //          listed under one name in a block of memory
   //          VERY SIMILAR to classes in other languages (but no methods)

//===================Example=1======================================

   struct Player player1;
   struct Player player2;

   strcpy(player1.name, "Bro");
   player1.score = 4;

   strcpy(player2.name, "Bra");
   player2.score = 5;

   printf("%s\n", player1.name);
   printf("%d\n", player1.score);

   printf("%s\n", player2.name);
   printf("%d\n", player2.score);


//====================Exampl=2====================================

   struct Student student1 = {"Spongebob", 3.0};
   struct Student student2 = {"Patrick", 2.5};
   struct Student student3 = {"Sandy", 4.0};
   struct Student student4 = {"Squidward", 2.0};

   struct Student students[] = {student1, student2, student3, student4};

   for(int i = 0; i < sizeof(students)/sizeof(students[0]); i++)
   {
      printf("name:%-12s\t", students[i].name);
      printf("gpa: %.2f\n", students[i].gpa);
   }

   return 0;
}