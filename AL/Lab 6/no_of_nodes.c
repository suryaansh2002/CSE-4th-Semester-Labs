//no_of_nodes.c

#include <stdio.h>
#include <stdlib.h>

int opcount=0;

typedef struct node{
	int val;
	struct node *left;
	struct node *right;
} *NODE;



NODE insertNode()
{
	int val;
	int check;
	printf("Enter the element : ");
	scanf("%d", &val);
	NODE cur = (NODE)malloc(sizeof(struct node));
	cur->val = val;
	cur->left = NULL;
	cur->right = NULL;
	printf("Insert Left child of %d? (Yes : 1,No : 0) : ", val);
	scanf("%d", &check);
	if (check)
		cur->left = insertNode();
	printf("Insert Right child of %d? (Yes : 1,No : 0) : ", val);
	scanf("%d", &check);
	if (check)
		cur->right = insertNode();
	return cur;
}

int countnodes(NODE header){
	if (!header)
	{
		return 0;
	}
	    opcount++;


    return 1 + countnodes(header->right) + countnodes(header->left);
}

int main()
{
	NODE header = insertNode();
	int num = countnodes(header);
	printf("\nThe Number of Nodes is : %d\n", num);
    printf("\nThe Opcount is : %d\n",opcount);
	return 0;
}
