
#include <stdlib.h>
#include <stdio.h>

void print_arr(int *arr, int n)
{
	int i = 0;
	while (i< n)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}

int can_put_queen(int *arr, int col, int row)
{
	int i;
	i = 0;
	while (i < col)
	{
		if (arr[i] == row)
			return (0);
		if (arr[i] + (col - i) == row)
			return (0);
		if (arr[i] - (col - i) == row)
			return (0);
		i++;
	}
	return (1);
}

void find_pos(int *arr, int col, int n)
{
	int row;
	if (col == n)
	{
		// printf("final = ");
		print_arr(arr, n);
		return;
	}
	row = 0;
	while (row < n)
	{
		if (can_put_queen(arr, col, row))
		{
			arr[col] = row;
			// print_arr(arr, n);
			find_pos(arr, col+1, n);
		}
		row++;
	}
}

int main(int ac, char **av)
{
	int n;
	int *arr;
	int i;

	if (ac != 2)
		return (1);
	n = atoi(av[1]);
	// printf("n=%d\n", n);
	if (n <= 2)
		return (0);

	arr = malloc(sizeof(int) * (n));
	if (!arr)
		return (1);
	i=0;
	while (i < n)
	{
		arr[i] = 0;
		i++;
	}

	find_pos(arr, 0, n);
	// print_arr(arr, n);
	return (0);
}