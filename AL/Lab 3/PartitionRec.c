#include <stdlib.h>
#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("-> ");
}

int sumArray(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int checkNotIn(int arr[], int key, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return 1;
        }
    }

    return 0;
}

void powerSets(int arr[], int sarr[], int n, int ai, int sai)
{

    if (ai >= n)
    {
        if (sumArray(arr, ai) == 2 * sumArray(sarr, sai))
        {
            printArray(sarr, sai);
            printf("%d\n", sumArray(sarr, sai));
            int arr2[100];
            int c = 0;
            for (int i = 0; i < n; i++)
            {

                if (checkNotIn(sarr, arr[i], sai) == 0)
                {
                    arr2[c] = arr[i];
                    c++;
                }
            }
            printArray(arr2, c);
            printf("%d\n", sumArray(arr2, c));

            exit(0);
        }

        return;
    }

    powerSets(arr, sarr, n, ai + 1, sai);
    sarr[sai] = arr[ai];
    powerSets(arr, sarr, n, ai + 1, sai + 1);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int sarr[] = {0, 0, 0, 0, 0, 0, 0};
    powerSets(arr, sarr, n, 0, 0);

    printf("No solution possible\n");

    return 0;
}