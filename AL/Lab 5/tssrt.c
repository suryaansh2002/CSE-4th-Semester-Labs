//Write a program to determine the Topological sort of a given graph using Source removal technique

#include <stdio.h>
#include <stdlib.h>

void insertEdge(int **mat, int first, int second)
{
 mat[first][second] = 1;
}

int check(int **mat, int num, int node)
{
 int result = 1;
 for (int i = 0; i < num; i++)
 {
 if (mat[i][node] == 1)
 {
 result = 0;
 }
 }
 return result;
}

void deleteEdge(int **mat, int num, int node)
{
 for (int i = 0; i < num; i++)
 {
 mat[node][i] = 0;
 }
}

void topologicalsort(int **mat, int num)
{
 int *removed = (int *)calloc(num, sizeof(int));
 for (int i = 0; i < num; i++)
 {
 removed[i] = 0;
 }
 int popped[num];
 int popIndex = 0;
 for (int i = 0; i < num; i++)
 {
 if (removed[i] == 0 && check(mat, num, i))
 {
 removed[i] = 1;
 popped[popIndex++] = i;
 deleteEdge(mat, num, i);
 i = 0;
 }
 }
 for (int i = 0; i < num; i++)
 {
 if (removed[i] == 0)
 {
 printf("The Graph is a Cyclic Graph.\n");
 return;
 }
 }
 printf("The Graph is a Directed Acyclic Graph\n Topologically Sorted order is:\n ");
 for (int i = 0; i < popIndex; i++)
 {
 printf("%d ", popped[i]);
 }
 printf("\n");
}

int main()
{
 int num;
 printf("Enter number of edges: \n");
 scanf("%d",&num);
 int **mat = (int **)calloc(num, sizeof(int *));
 for (int i = 0; i < num; i++)
 {
 mat[i] = (int *)calloc(num, sizeof(int));
 for (int j = 0; j < num; j++)
 {
 mat[i][j] = 0;
 }
 }
 int m,n;
  printf("Enter the pairs of vertices to be joined:(directed)\n(Indexing starts from 0) \n(Enter -1 -1 once all vertices pairs have been entered)\n\n");

 do{
 printf("Enter vertices pair: ");
 scanf("%d %d",&m,&n);
 if(m!=-1 && n!=-1)
 insertEdge(mat, m, n);
 }while(m!=-1);
 topologicalsort(mat, num);
 return 0;
}