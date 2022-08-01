#include <stdio.h>
#include <stdlib.h>

int main(){

// contiune = skips the rest of the code & forces the next iteration of the loop.
// Break = exits a loop/ switch.


for(int i = 1; i <= 20; i++){
    if(i == 13){
        continue; // skips 13
        //break; // stops the loop after 12
    }
    printf("%d\n", i);
}

}