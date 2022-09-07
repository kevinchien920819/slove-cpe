#include <stdio.h>

int counting(unsigned long long int n,int count){
    
    count = n % 10 + count;
    n = n / 10;
    if(n == 0 ) 
		return count;
    return counting(n,count);
}
int main (){
    unsigned long long int n ;
    while(scanf("%llu",&n)){
        if(n == 0)
            return 0;
        else
            printf("%d\n",counting(n,0));
    }
}
