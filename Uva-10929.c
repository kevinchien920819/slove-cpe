#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
char number[1001] = {'0'};
while(scanf("%s",&number)){
if(number[0]=='0')
    return 0;
    int odd = 0,even = 0;
    for(int i=1;i < strlen(number);i= i+2){
        odd = (int)(number[i] - 48) + odd;
    }
    for(int i=0;i < strlen(number);i=i+2){
        even = (int)(number[i] - 48) + even;
    }
    if(even > odd){
        int temp = even;
        even = odd;
        odd = temp;
    }
    if((odd - even) % 11 == 0){
        printf("%s is a multiple of 11.\n",number);
    }
    else if((odd - even) % 11 !=0)
    printf("%s is not a multiple of 11.\n",number);
}
}