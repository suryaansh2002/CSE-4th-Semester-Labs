#include <stdio.h> 
#include <string.h>

void stringmatch(char text[],char check[]){
		int count=0;
int flag=0;
	for(int i=0;i<strlen(text)-strlen(check)+1; i++){
		flag=0;
		count+=1;
		if(text[i]==check[0]){
			count-=1;
			for(int j=0;j<strlen(check);j++){
				count+=1;
				if(text[i+j]==check[j]){
				}
				if(text[i+j]!=check[j]){
					break;
				}
				if(j==strlen(check)-1){
					flag=1;
					break;
				}
			}

		}
		if(flag==1){
			printf(" match starts at %d\n",i);
			break;
		}
	}
	printf("\n opCount is %d \n",count);
	if(flag==0){
		printf("Substring not found");
	}
}

int main(){
stringmatch("What are you doing", "oin");
}