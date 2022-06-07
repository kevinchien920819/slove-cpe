#include<stdio.h>
#include<stdlib.h>
int main(){
    unsigned long long int hashmat,opponent;
    while (scanf("%llu %llu",&hashmat,&opponent)!= EOF)
    {
        printf("%llu\n",abs(opponent - hashmat));
    }
    system("pause");
    return 0;

}