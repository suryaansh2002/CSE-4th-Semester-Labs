#include<stdio.h>
#include <stdlib.h>


int main(){
    int v,e;
    printf("Enter no. of vertices: ");
    scanf("%d",&v);
     printf("Enter no. of edges: ");
    scanf("%d",&e);
    int mat[v][v];
    for(int m=0;m<v;m++){
        for(int n=0;n<v;n++){
            mat[m][n]=0;
        }
    }
    int v1,v2;
    for(int i=1;i<e+1; i++){
        printf("Enter the Vertices (between 1-%d) for Edge %d:",v,i);
        scanf("%d %d",&v1,&v2);
        mat[v1-1][v2-1]=1;
        mat[v2-1][v1-1]=1;
        
    }
    printf("Adjacency Matrix:\n");
    printf("\n");
    printf("   ");
    for(int m=0;m<v;m++){
        printf("%d\t",m+1);
    }
    printf("\n");
    printf("\n");

    for(int m=0;m<v;m++){
        printf("%d  ", m+1);
        for(int n=0;n<v;n++){
        printf("%d\t",mat[m][n]);

        }
        printf("\n");
    }

    printf("Adjacency List \n");
    for(int m=0;m<v;m++){
        printf("%d -> ", m+1);
        for (int n = 0; n < v; n++)
        if(mat[m][n]==1){
            printf("%d ",n+1);
        }
       
        printf("\n" );
    }
}