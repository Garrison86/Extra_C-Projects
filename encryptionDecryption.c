#include <stdio.h>
#include <assert.h>


char *getEnDeCryptMessage(char *, char *);

int main(void){

    char message[2000] = {'\0'}, enDeCryptString[100] = {'\0'};
    printf("\nEnter the message to be encrypted or decrypted (max 2000 chars): ");
    gets(message);


    printf("Enter the encryption/decryption string (max 100 chars): ");
    gets(enDeCryptString);

    printf("The encypted/decrypted string is: %s\n\n", getEnDeCryptMessage(message, enDeCryptString));

}
    char *getEnDeCryptMessage(char *message, char *enDeCryptStr){
        char *startEncrypt = enDeCryptStr;
        char *startMess = message; // save starting addresses

        while (*message){ // loop until ('\0') encountered
            // XOR the message char with each encrypt string char
            *message ^= (*enDeCryptStr++);
            // offset to the start of printable chars, i.e. space
            *message += ' ';
            // reset encrypt string to start if '\0' encountered
            if (!*enDeCryptStr){
                enDeCryptStr = startEncrypt;
                message++; // point to next char in message
        }
        return startMess; // return encrypted/decrypted string
    }
}