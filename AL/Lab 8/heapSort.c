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

Node *levelOrderTravCount(Node **root, int num)
{
    int count = 0;
    QNode *front = NULL, *rear = NULL;
    insNode(&front, &rear, *root);

    while (front)
    {
        Node *temp = front->node;
        delNode(&front, &rear);
        count++;
        if (count == num)
        {
            return temp;
        }

        if (temp->left)
            insNode(&front, &rear, temp->left);

        if (temp->right)
            insNode(&front, &rear, temp->right);
    }
}

Node *max(Node *a, Node *b)
{
    if (!b)
    {
        return a;
    }

    return a->data > b->data ? a : b;
}

void heapifyDown(Node *cur, int *comp)
{
    if (!cur)
    {
        return;
    }
    if (!cur->left)
    {
        return;
    }
    Node *maxChild;
    if (!cur->right)
    {
        maxChild = cur->left;
    }
    else
    {
        maxChild = max(cur->left, cur->right);
    }
    if (maxChild->data > cur->data)
    {
        while (maxChild->data > cur->data)
        {
            int temp = maxChild->data;
            maxChild->data = cur->data;
            cur->data = temp;
            cur = maxChild;
            if (cur->left || cur->right)
            {
                maxChild = max(cur->left, cur->right);
            }
        }
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
    }

    for (int i = n / 2; i > 0; i--)
    {
        Node *cParent = levelOrderTravCount(&root, i);
        heapifyDown(cParent, &comp);
    }

    int arr[n + 1];
    int ind = 0;

    for (int i = n; i > 0; i--)
    {
        arr[ind++] = root->data;

        for (int j = (i - 1) / 2; j > 0; j--)
        {
            Node *cParent = levelOrderTravCount(&root, j);
            heapifyDown(cParent, &comp);
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}