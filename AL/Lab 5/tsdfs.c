
  //Write a program to determine the Topological sort of a given graph using  Depth-First technique 
#include<stdio.h>
 
void DFS(int);


int G[10][10],visited[10],n,pop[10],pi=0;;    //n is no of vertices and graph is sorted in array G[10][10]

void printArr(int arr[],int n){
   for (int i = n-1; i>=0; i--)
   {
      printf("\t%d",arr[i] );
   }
   printf("\n");
}

void main()
{
    int i,j;
    printf("Enter number of vertices:");
  
scanf("%d",&n);
printf("\nEnter adjecency matrix of the graph:\n");
  
for(i=0;i<n;i++)
       for(j=0;j<n;j++)
scanf("%d",&G[i][j]);
   for(i=0;i<n;i++)
      
        visited[i]=0;

    for(int i=0;i<n;i++){
      if(!visited[i]){
         DFS(i);
      }
    }
   
printf("\nTopological sorting order is:");


printArr(pop,n);
}

void DFS(int i)
{
    int j;
    visited[i]=1;
for(j=0;j<n;j++){
       if(!visited[j]&&G[i][j]==1)
            DFS(j);

}

pop[pi++]=i;   
}
