#include <stdio.h>

int counting(int n){
    int count = 0;
    count = n % 10 + count;
    n = n / 10;
    if(n == 0 && count / 10 ==0) return count;
    return counting(n);
}
int main (){
    int n ;
    while(scanf("%d",&n)){
        if(n == 0)
            return 0;
        else        
            printf("%d\n",counting(n));
    }
}