#include <stdio.h>
#include <assert.h>
#include <time.h>

typedef struct hms {
   unsigned int hrs;
   unsigned int mins;
   unsigned int secs;
} hms;

void showNBits(int, int);  // forward declarations 
hms secsToHMS(time_t);
int main(void) {

   hms tm = {0};
   time_t T0 = time(NULL), dT;
printf("Here is the time in binary H:M:S \n");
   while(1) {
      dT = time(NULL) - T0;
      tm = secsToHMS(dT);
      showNBits(tm.hrs, 5); printf(":"); // max hrs =  24 < 2^5
      showNBits(tm.mins,6); printf(":"); // max mins = 60 < 2^6
      showNBits(tm.secs,6); printf("\r");// max secs = 60 < 2^6
   }
}
void showNBits(int iMyVal, int iNBits){ 
   unsigned int iBitMask = 0x80000000; 
   assert((iNBits <= 32) && (iNBits >= 0));
   iBitMask >>= (32-iNBits);  // unless iNBits=0!
	
   while(iBitMask){ 
      printf((iMyVal & iBitMask)?"1":"0"); 
      iBitMask >>= 1; 
   } 
}  

hms secsToHMS(time_t secs){
   hms difTime = {0};
   difTime.hrs = secs/3600;
   difTime.mins = (secs%3600)/60;
   difTime.secs = (secs%60);
   return (difTime);
} 