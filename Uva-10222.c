#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
char keyboardTable[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./"; 
int keyboardTableSize = strlen(keyboardTable);
    char text[100000] = {'\0'};
    while (gets(text)){
for(int i = 0; i < strlen(text); i++)
{
    text[i] = tolower(text[i]);
}
    for(int i=0; i < strlen(text); i++){
        for(int j = 0; j < keyboardTableSize;j++){
            if(text[i] == keyboardTable[j])
                text[i] = keyboardTable[j-2];   
        }
    }
        puts(text);
    }
    
}