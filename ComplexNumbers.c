/* Revision 1.1.  loadComplex() changed, to return Complex structure */
#include <stdlib.h>
#include <stdio.h>
#include <complex.h>

typedef struct {
   double real; 
   double imag; 
} Complex;

#define Exit 0
#define Load 1
#define Display 2
#define Move 3
#define Conjugate 4
#define Add 5
#define Subtract 6
#define Multiply 7
#define Divide 8

#define PROMPT_USER_TO(menuItem) printf("%d. %s complex numbers\n", menuItem, #menuItem);

// Forward declarations
// TODO: add other forward declarations, as required
int  displayMenu();
void executeMenuItem(int menuItem);
Complex loadComplex();
int chooseComplexNumberTo(char*);
Complex complexConjugate(double c);
Complex add(double a, double b);
Complex subtract(double a, double b);
Complex multiply(double a, double b);
Complex divide(double a, double b);
char display();
// DO NOT CHANGE THIS FUNCTION
int main(void){   
   int choice = Exit;
   printf("Welcome to the complex number calculator\n\n");
   do{
      choice = displayMenu();
	   executeMenuItem(choice);
   } while (choice != Exit);

   printf("Program exited\n");
   exit(EXIT_SUCCESS);
}

// display menu options, prompt the user to enter a choice, and return the value selected
// DO NOT CHANGE THIS FUNCTION
int displayMenu(){  
    int input = Exit;
    printf("Select one of the following:\n\n");
    PROMPT_USER_TO(Load)
    PROMPT_USER_TO(Display)
    PROMPT_USER_TO(Move)
    PROMPT_USER_TO(Conjugate)
    PROMPT_USER_TO(Add)
    PROMPT_USER_TO(Subtract)
    PROMPT_USER_TO(Multiply)
    PROMPT_USER_TO(Divide)
    printf("%d. Exit Program\n", Exit);
    scanf("%d", &input);
    return input;
}

// DO NOT CHANGE THIS FUNCTION
void executeMenuItem(int menuItem){
    Complex c = {0,0};  // c is used for temporary storage of Complex numbers; it is not used in calculations
    static Complex c0 = {0,0}, c1 = {0,0}, cResult = {0,0};   // Use these values for all operations below
    // Note that cResult is never used in calculations directly, only to store the result of calculations
 
    switch (menuItem) {

        case Exit: break; // do not edit this; 'Exit' is handled in the 'while' statement

        case Load:        // load c0 or c1 with real and imaginary values 
            if (chooseComplexNumberTo("load"))
               c1 = loadComplex();
            else
               c0 = loadComplex();
            break;

/*        TODO: write the following methods to move, display, conjugate, add, etc. the
          Complex number stored in c0 and c1, as indicated.  The method chooseComplexNumberTo() 
          has already been written for you (below); it should not be altered.
*/
        case Display:  // displays the result of a computation
           c = chooseComplexNumberTo("display")?c1:c0;
           display(c); 
           break;  

        case Move: // move the cResult to c1 or c0
            // use the value indicated by chooseComplexNumberTo("set equal to the result") to 
	    // determine whether cResult is copied to c1 or c0
            break; 

        case Conjugate:  // converts c to c*, i.e. real + imag *i -> real - imag * i
           // use chooseComplexNumberTo("conjugate") and then conjugate c1 or c0 accordingly
           c = complexConjugate(c1);		// store the conjugated result back in c, i.e. c -> c*
           display(c);
           break;

        case Add:        // add c0 + c1 and store to cResult
           cResult = add(c0, c1); 
           display(cResult);
           break;      

        case Subtract:   // subtract c1 - c0 and store to cResult
           cResult = subtract(c0, c1); 
           display(cResult);
           break;

        case Multiply:   // etc....multiply c1 * c0
                cResult = subtract(c0, c1); 
           display(cResult);
           break;
        case Divide:     // etc....divide c1/c0 using (c1 * c0*)/(c0 * c0*)
                         // use an assert() statement to check for division by 0+0i
                         assert();
            cResult = divide(c0, c1); 
           display(cResult);
           break;
                      
        
        default:
            printf("Bad menu value entered; ");
    }
    printf("\n");
}

// DO NOT CHANGE THIS FUNCTION
Complex loadComplex(){
   Complex cTemp;
   printf("\tEnter the real component : ");
   scanf("%lf", &cTemp.real);

   printf("\tEnter the imaginary component : ");
   scanf("%lf", &cTemp.imag);
   printf("\n");
   return cTemp;
}

// DO NOT CHANGE THIS FUNCTION
int chooseComplexNumberTo(char* operation){
    int choice = 0;
    printf("\nWhich complex number do you wish to %s? (enter 0 or 1): ", operation);
    scanf("%d", &choice);
    return choice;
}
Complex complexConjugate(c){
    c.real = conj(c.real);
    c.imag = conj(c.image);
    return c;
}
Complex subtract(Complex h, Complex f){
    double x, a, B, Y;
    a = c0.real; 
    B = c0.imag;
    x = c1.real;
    Y = c0.imag;
    Complex cResult = (a - x) + (B-Y);
    return cResult;
}
Complex multiply(Complex h, Complex f){
    double x, a, B, Y;
    a = c0.real; 
    B = c0.imag;
    x = c1.real;
    Y = c0.imag;
    Complex cResult = ((a * x) - (B * Y)) + ((a*Y) + (x*B));
    return cResult;
}
Complex add(Complex h, Complex f){
    double x, a, B, Y;
    a = c0.real; 
    B = c0.imag;
    x = c1.real;
    Y = c0.imag;
    Complex cResult = (a + x) + (B+Y);
    return cResult;
}
Complex division(Complex h, Complex f){
    double x, a, B, Y;
    a = conj(c0.real); 
    B = conj(c0.imag);
    x = c1.real;
    Y = c0.imag;
    Complex cResult = ((a*x) + (B*Y)) / (((a^2)+(B^2))) + (((a*Y)-(B*x))/((a^2)+(B^2)));
    return cResult;
}
char display(Complex element){
char p1 = element.real;
char p2 = element.imag;
printf(p1+" + "+p2);
}

// TODO: add all additional funtions here, as specified above in the executeMenuItem() method.