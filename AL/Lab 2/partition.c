#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void main(){
    int n=5;
    int count=0;
    int arr[]={1,2,6,8,11};
    int max_val = pow(2,n);
    int total_sum=0;
    for(int i=0;i<n;i++)
        total_sum+=arr[i];
    int cur_sum=0;
    int sol=0;
    for(int ctr=0;ctr<max_val;ctr++){
        cur_sum=0;
        for(int j=0;j<n;j++){
            count +=1;
            if((1<<j) & ctr){
                cur_sum+=arr[j];
            }
        }
        if(cur_sum*2==total_sum){
            printf("Sum of each subarray is: %d\n",cur_sum);
            sol++;
            printf("Subset 1\n");
            for(int j=0;j<n;j++){
            count +=1;

                if((1<<j) & ctr)
                    printf("%d ",arr[j]);
            }
            printf("\nSubset 2\n");
            for(int j=0;j<n;j++){
            count +=1;

                if(!((1<<j) & ctr))
                    printf("%d ",arr[j]);
            }
            break;
            printf("\n\n");
            }
        }
        printf("\nOpcount is %d\n ",count);
        if(!sol){
            printf("No solution possible\n");    
        }
        printf("\n");
}