 //Write a program to find diameter of a binary tree. Diameter of a binary tree is the longest path between any two nodes. 

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
 int val;
 struct node *left;
 struct node *right;
} * NODE;


NODE insertNode(){
 int val;
 int check;
 printf("Enter element : ");
 scanf("%d", &val);
 NODE n = (NODE)malloc(sizeof(struct node));
 n->val = val;
 n->left = NULL;
 n->right = NULL;
 printf("Insert Left of %d : (Yes : 1, No : 0) : ", val);
 scanf("%d", &check);
 if (check)
 n->left = insertNode();
 printf("Insert Right of %d : (Yes : 1, No : 0) : ", val);
 scanf("%d", &check);
 if (check)
 n->right = insertNode();
 return n;
}

int max(int a, int b)
{
 return a > b ? a : b;
}

int height(NODE head)
{
 if (head == NULL)
 {
 return -1;
 }
 return max(height(head->left), height(head->right)) + 1;
}

void diameter(NODE cur, int *max)
{
 if (cur)
 {
 int currentDiameter = height(cur->left) + height(cur->right) + 1;
 if (currentDiameter > *max)
 {
 *max = currentDiameter;
 }
 diameter(cur->left, max);
 diameter(cur->right, max);
 }
}

int main()
{
 NODE head = insertNode();
 int dia = -1;
 diameter(head, &dia);
 printf("\nThe Diameter of the Binary Tree is : %d\n", dia);
 return 0;
}