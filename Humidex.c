#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ABS_ZERO (-273.15)   // 0 𝒐𝑲 = -273.15 𝒐𝑪
#define getDegreesK(cTemp) ((double)(cTemp) - ABS_ZERO)

double getTdewC(double cT, double RH){
   double B;
   const double b = 17.27, c = 237.3;
   B = (log(RH / 100.0) + ((b * cT) / (c + cT))) / b;
   return((c * B) / (1.0 - B));
}
double HumidexC(double TempC, double relHumidity){
   double TdewC, TdewK, HMDX;
   TdewC = getTdewC(TempC, relHumidity);
   TdewK = getDegreesK(TdewC);
   HMDX = TempC + (1393438267 * exp(-5417.753/TdewK)) - 55.55;
   return (HMDX > 0.00 ? HMDX : 0.00); // ternary operator “?”
}
int main(void){

   unsigned int TempC, relHumidity;

   printf("\nEnter the current air temperature "
      "in degrees Celsius:");
   scanf("%u", &TempC);

   printf("Enter the humidity "
      "as a percent (without the %% sign, e.g. 87): ");
   scanf("%u", &relHumidity);
   assert(relHumidity > 0);

   printf("With Humidex added, the temperature feel like "
      "%5.1lf: \n\n", HumidexC(TempC, relHumidity));
}
