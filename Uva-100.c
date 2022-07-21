#include<stdio.h>

int main(){
    long long int i,j,start,end;
    while(scanf("%lld %lld",&i,&j) != EOF && i > 0 && j > 0){
        if(i > j){
            start = j;
            end = i;
        }
        else{
            start = i;
            end = j;
        }
        long long int max = 0;
        for(int i = start; i <= end;i++){
        int current = i,counter = 1;
        //the 3n+1 algorithm
        while(current != 1){
            counter += 1;
            if (current % 2 == 1){
                current = current * 3 + 1;
            }
            else{
                current = current / 2;
            }
        }
        if(counter > max)
            max = counter;
        }
        printf("%lld %lld %lld\n",i,j,max);
    }
}