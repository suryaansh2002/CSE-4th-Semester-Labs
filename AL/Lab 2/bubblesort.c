#include <stdio.h>

void bubbleSort(int arr[], int n){
	int temp,x=0;
for(int i=0;i<n-1;i++){
	for(int j=0;j<n-i-1;j++){
		x+=1;
		if(arr[j]>arr[j+1]){
		printf("swapping %d with %d\n", arr[j],arr[j+1]);
			temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
		}
	}
}

printf("\nCount is %d\n",x);


}

int main(){
	int n=10;
	int arr[]={7,81,18,5,29,24,28,15,19,8};
	
	for(int i=0; i<n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	bubbleSort(arr,n);
	for(int i=0; i<n; i++){
		printf("%d ",arr[i]);
	}

}