#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


char alpha[36] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";//the sheet of all alpha
char mirror[36] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";//the sheet of mirror alpha
char arr[21];//the input array

// pending whether it is palindrome
int palindrome(){ 
	
	for(int i = 0 ; i < strlen(arr) / 2 + 1; i ++){
		if(arr[i] != arr[strlen(arr) -1 - i])
			return 0;
	}
		return 1;
}

//check wheher it is mirror string
int mirrored(){
	int temp;
	for(int i =0 ; i < strlen(arr) /2 + 1 ; i ++){
		if(isdigit(arr[i])) // check whether it is number
			temp = arr[i] - '1' + 26; // if true temp means their index
		else//else then means it is alpha
			temp = arr[i] - 'A';//then temp means their index
		if(mirror[temp] != ' '){//if mirror[temp] == ' ' maens there is no mirror alpha so return 0
			if(arr[strlen(arr) -1 - i] != mirror[temp])// check each one of alpha in string is mirror word
				return 0;//if not then return 0
		}
		else
			return 0;
	}
	return 1;

}

int main(){
	while(scanf("%s",arr)!=EOF){//scanf untill there is no more data
		if(mirrored() && palindrome()){//if mirrored and palindrome == 1 means id a mirror palindrome
			printf("%s -- is a mirrored palindrome.\n",arr);
		}
		else if(mirrored()) {//mirror string
			printf("%s -- is a mirrored string.\n",arr);
		}
		else if(palindrome()){//palidrome string
			printf("%s -- is a regular palindrome.\n",arr);
		}
		else{//not palidrome string
			printf("%s -- is not a palindrome.\n",arr);
		}
		printf("\n");
		}
		return 0;


}
