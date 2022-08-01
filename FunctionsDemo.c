#include <stdio.h>
#include <stdlib.h>

double f(double x);
double sumOfSquares(double f(double x), int n);
double inverse(double x);

//double sumOfSaquares(double (*f)(double x), int);
// -- any one of the following works equally well. --
//double sumOfSqaures(double f(double), int );
//double sumOfSqaures(double (*f)(double), int );
//double sumOfSqaures(double (*)(double x), int );
//double sumOfSqaures(double (double), int ); //!!!

int main(){


double result = sumOfSquares(inverse, n);
    return 0;
}

double sumOfSquares(double f(double x), int n){
    double sum = 0.0;
    for(int i=1; i <= n; ++i)
        sum += f(i) * f(i);
        return sum;
}
double inverse(double x){
    return (1.0/x);
}