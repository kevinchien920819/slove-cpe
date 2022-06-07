#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void insertion_sort(int*,int);
int main(){
    int r;
    scanf("%d",&r);
    for (int i = 0; i < r; i++)
    {
        int s;
        scanf("%d",&s);
        int num[500] = {0};
        int count = 0;
        for (int j = 0; j < s; j++)
        {
            scanf("%d",&num[j]);
        }
        insertion_sort(num,s);
        int n;
        if(s % 2 ==0)
            n = s / 2 - 1;
        else
            n = s / 2;
        int ans = 0;
        for(int j = 0; j < s ;j++){
            ans = abs(num[j] - num[n]) + ans;
        }
        printf("%d\n",ans);
    }
    
    system("pause");
}
void insertion_sort (int num[],int n){
for (int i = 0; i < n; i++)
{ 
    int j = i - 1;
    int key = num[i];
    int flag = 0;
    while (num[j] > key && j >= 0){
        int temp = num[j];
        num[j] = num[j+1];
        num[j+1] = temp;
        j--;
        flag = 1;
    }
}
}