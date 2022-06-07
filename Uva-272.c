#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    char text;
    int count = 0;
    while(scanf("%c", &text) != EOF){
        if(text != '\"')
            printf("%c", text);
        else{
            count++;
            if(count % 2 == 0)
                printf("''");
            else 
                printf("``");
        }
    }
}