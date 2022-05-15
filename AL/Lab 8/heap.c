#include <stdio.h>
#include <stdlib.h>

typedef struct QNode QNode;
typedef struct Node Node;

struct Node
{
    int data;
    Node *left, *right, *parent;
};

struct QNode
{
    QNode *next;
    Node *node;
};

void insNode(QNode **front, QNode **rear, Node *node)
{
    QNode *new_node = (QNode *)malloc(sizeof(QNode));
    new_node->next = NULL;
    new_node->node = node;

    if (!(*rear))
    {
        *rear = new_node;
        *front = *rear;
    }
    else
    {
        (*rear)->next = new_node;
        *rear = new_node;
    }
}

void delNode(QNode **front, QNode **rear)
{
    if (!(*front))
        return;

    QNode *temp = *front;
    *front = (*front)->next;

    if (!(*front))
        *rear = NULL;
    free(temp);
}

Node *levelOrderIns(Node **root, int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->left = new_node->right = NULL;
    new_node->data = data;
    if (!*root)
    {
        new_node->parent = NULL;
        *root = new_node;
        return new_node;
    }

    QNode *front = NULL, *rear = NULL;
    insNode(&front, &rear, *root);

    while (front)
    {
        Node *temp = front->node;
        delNode(&front, &rear);

        if (temp->left)
            insNode(&front, &rear, temp->left);
        else
        {
            temp->left = new_node;
            new_node->parent = temp;
            return new_node;
        }

        if (temp->right)
            insNode(&front, &rear, temp->right);
        else
        {
            temp->right = new_node;
            new_node->parent = temp;
            return new_node;
        }
    }
    return new_node;
}

void levelOrderTrav(Node **root)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->left = new_node->right = NULL;
    if (!*root)
    {
        new_node->parent = NULL;
        *root = new_node;
        return;
    }

    QNode *front = NULL, *rear = NULL;
    insNode(&front, &rear, *root);

    while (front)
    {
        Node *temp = front->node;
        delNode(&front, &rear);
        printf("%d ", temp->data);

        if (temp->left)
            insNode(&front, &rear, temp->left);

        if (temp->right)
            insNode(&front, &rear, temp->right);
    }
}

void heapifyUp(Node *cur, int *comp)
{
    while (cur->parent && cur->data > cur->parent->data)
    {
        int temp = cur->data;
        cur->data = cur->parent->data;
        cur->parent->data = temp;
        cur = cur->parent;
    }
}

void main()
{
    int n, val;
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    int comp = 0;

    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        Node *cur = levelOrderIns(&root, val);
        heapifyUp(cur, &comp);
    }

    levelOrderTrav(&root);
}