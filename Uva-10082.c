#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main (){
    char arr [79] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./ ";

    char check[100] = {'\0'};
    while (gets(check)){
        for (int i = 0; i < 100;i++){
            for (int j = 0; check[i] != check[j]; j++){
            if(check[i] == check[j])
            
            }
        }
    }
    

}