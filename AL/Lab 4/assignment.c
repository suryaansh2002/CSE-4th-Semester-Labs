#include <stdio.h>
#include <stdlib.h>


void printArr(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void generatePerms(int n, int curr_perm[], int best[], int i, int *cost, int cost_arr[][n], int *opcount)
{

	if (i == n - 1)
	{
		*opcount += 1;
		int cur_cost = 0;
		for (int j = 0; j < n; j++)
		{
			cur_cost += cost_arr[j][curr_perm[j]];
		}

		if (cur_cost < *cost)
		{
			*cost = cur_cost;
			for (int k = 0; k < n; k++)
			{
				best[k] = curr_perm[k];
			}
		}
	}

	for (int j = i; j < n; j++)
	{
		int temp = curr_perm[i];
		curr_perm[i] = curr_perm[j];
		curr_perm[j] = temp;

		generatePerms(n, curr_perm, best, i + 1, cost, cost_arr, opcount);

		temp = curr_perm[i];
		curr_perm[i] = curr_perm[j];
		curr_perm[j] = temp;
	}
}

int main()
{

	int n;
	printf("Enter The number of jobs and people:");
	scanf("%d", &n);
	int curr_perm[n];
	int best[n];
	int cost_arr[n][n];
	printf("Enter the adjacency matrix : \n");

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &cost_arr[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		curr_perm[i] = i;
		best[i] = i;
	}
	int cost = 1000;
	int ind = 0;
	int opcount = 0;
	generatePerms(n, curr_perm, best, ind, &cost, cost_arr, &opcount);
	printf("The minimum cost possible is: %d\n", cost);
	printf("The required distribution of jobs is: ");
	printArr(best, n);

	printf("The opcount is: %d", opcount);
	return 0;
}
