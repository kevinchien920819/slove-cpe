#include<stdio.h>
#include<string.h>

int main(){
    char input[1000];//set input arr
    while (gets(input)){//get input
        int count [128] = {0};//counter array
        for (int i = 0; i < strlen(input); i++)
        {
            count[input[i]]++;//if input[i] to ascii  in count then count[input[i]]++
        }
        for (int i = 1; i <= strlen(input); i++)
        {
            for (int j = 128; j >= 0; j--)
            {
                if(count[j] == i&&count[j] > 0){//check if count[i] == 0 or not if not print value
                    printf("%d %d\n",j,i);
                }
            }
            
        }
            printf("\n");
        
    }
    
}