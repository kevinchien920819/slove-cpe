#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int calculate(long long x){
    if(x / 10000000 > 0){
        calculate(x / 10000000);
        printf(" kuti");
        x = x % 10000000;
        if(x > 0)
            printf(" ");
    }
    if(x / 100000 > 0){
        printf("%lld lakh", x / 100000);
        x = x % 100000;
        if(x > 0)
            printf(" ");
    }
    if(x / 1000 > 0){
        printf("%d hajar", x / 1000);
        x = x % 1000;
        if(x > 0)
            printf(" ");
    }
    if(x / 100 > 0){
        printf("%d shata", x / 100);
        x = x % 100;
        if(x > 0)
            printf(" ");
    }
    if(x > 0){
        printf("%lld",x);
    }

}
int main(){
long long input;
// kuti = 10000000 8
// lakh =  100000 6 
// hajar = 1000   4
// shata = 100    3
int count = 0;
while(scanf("%lld", &input)!=EOF){
    count++;
    printf("%4d. ", count);
    if(input == 0)
        printf("%d",input);
    else
        calculate(input);
printf("\n");
}
}