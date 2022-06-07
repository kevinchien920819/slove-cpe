#include<stdio.h>
#include<string.h>

int main(){
char a[1001] = {};
char b[1001] = {};

while(gets(a) && gets(b)){
int frequency_a[26] = {};
int frequency_b[26]={};
int alen = strlen (a);
int blen = strlen (b);
int len;
int counter =0;
for(int i = 0; i < alen;i++)
	frequency_a[a[i] - 'a']++;
for(int i = 0; i < blen;i++)
	frequency_b[b[i] - 'a']++;

for(int i = 0; i < 26; i++){
	while(frequency_a[i] > 0 && frequency_b[i] > 0){
		printf("%c",i + 'a');
		frequency_a [i]--;
		frequency_b[i]--;
	}
}
printf("\n");
}
}