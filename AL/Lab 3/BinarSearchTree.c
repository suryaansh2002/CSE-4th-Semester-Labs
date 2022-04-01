#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int key;
    struct node *left, *right;
};
struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(int key, struct node *root)
{
    if (root == NULL)
    {
        root = newNode(key);
        printf("%d inserted successfully!\n", key);

        return root;
    }
    struct node *temp = root;
    while (1)
    {
        if (key == temp->key)
        {
            printf("element already present in tree");
            return root;
        }
        if (key < temp->key)
        {
            if (temp->left == NULL)
            {
                temp->left = newNode(key);
                break;
            }
            else
            {
                temp = temp->left;
            }
        }
        if (key > temp->key)
        {
            if (temp->right == NULL)
            {
                temp->right = newNode(key);
                break;
            }
            else
            {
                temp = temp->right;
            }
        }
    }
    printf("%d inserted succcessfully", key);
}

void search(int key, struct node *root)
{
    if (root == NULL)
    {
        printf("%d not present in tree\n", key);
        root = insert(key, root);
        return;
    }
    struct node *temp = root;
    while (1)
    {
        if (key == temp->key)
        {
            printf("%d found in tree\n", key);
            break;
        }

        if (key < temp->key)
        {
            if (temp->left == NULL)
            {
                printf("%d not present in tree\n", key);
                temp->left = newNode(key);
                printf("%d inserted successfully!\n", key);
                break;
            }
            else
            {
                temp = temp->left;
            }
        }
        if (key > temp->key)
        {
            if (temp->right == NULL)
            {
                printf("%d not present in tree\n", key);

                temp->right = newNode(key);
                printf("%d inserted successfully!\n", key);
                break;
            }
            else
            {
                temp = temp->right;
            }
        }
    }
}

struct sNode
{
    struct node *t;
    struct sNode *next;
};

void push(struct sNode **top_ref, struct node *t)
{
    struct sNode *new_node =
        (struct sNode *)malloc(sizeof(struct sNode));

    new_node->t = t;

    new_node->next = (*top_ref);

    (*top_ref) = new_node;
}

bool isEmpty(struct sNode *top)
{
    return (top == NULL) ? 1 : 0;
}

struct node *pop(struct sNode **top_ref)
{
    struct node *res;
    struct sNode *top;

    top = *top_ref;
    res = top->t;
    *top_ref = top->next;
    free(top);
    return res;
}

void inOrder(struct node *root)
{
    struct node *current = root;
    struct sNode *s = NULL;
    bool done = 0;

    while (!done)
    {
        if (current != NULL)
        {

            push(&s, current);
            current = current->left;
        }

        else
        {
            if (!isEmpty(s))
            {
                current = pop(&s);
                printf("%d ", current->key);

                current = current->right;
            }
            else
                done = 1;
        }
    }
}

void preOrder(struct node *root)
{
    struct node *current = root;
    struct sNode *s = NULL;

    push(&s, current);

    while (!isEmpty(s))
    {
        current = pop(&s);
        printf("%d\n", current->key);
        if (current->right)
        {
            push(&s, current->right);
        }
        if (current->left)
        {
            push(&s, current->left);
        }
    }
}

void postOrder(struct node *root)
{
    struct sNode *s = NULL;

    push(&s, root);

    struct sNode *disp;
    disp = NULL;

    while (!isEmpty(s))
    {
        struct node *curr = pop(&s);
        push(&disp, curr);

        if (curr->left)
            push(&s, curr->left);
        if (curr->right)
            push(&s, curr->right);
    }

    while (!isEmpty(disp))
    {
        struct node *temp = pop(&disp);
        printf("%d ", temp->key);
    }
}

int main()
{

    int men = 0;
    struct node *root = NULL;
    while (1)
    {
        printf("Enter:\n1 to insert\n2 to search\n3 to display in inorder\n4 to display in preorder\n5 to display in postorder\n6 to exit:\n ");

        scanf("%d", &men);

        if (men == 1)
        {
            int item;
            printf("Enter the elemnt you want to insert:");
            scanf("%d", &item);
            root = insert(item, root);
        }
        if (men == 2)
        {
            int item;
            printf("Enter the elemnt you want to search for:");
            scanf("%d", &item);
            search(item, root);
        }
        if (men == 3)
        {
            inOrder(root);
        }
        if (men == 4)
        {
            preOrder(root);
        }
        if (men == 5)
        {
            postOrder(root);
        }
        if (men == 6)
        {
            break;
        }
    }

    return 0;
}