
#include <stdio.h>
#include <stdlib.h>

// void print_indexs(int *arr, int len)
// {
// 	int i;

// 	i = 0;
// 	while (i < len)
// 	{
// 		printf("%d ", arr[i]);
// 		i++;
// 	}
// 	printf("\n");
// }

void check_sum(int *arr_index, int len, int sum, int *arr_num)
{
	int num_sum;
	int i;
	int count_no_index;
	int should_print_space;

	num_sum = 0;
	i = 0;
	count_no_index = 0;
	while (i < len)
	{
		if (i == arr_index[i])
			num_sum += arr_num[i];
		else
			count_no_index++;
		i++;
	}
	should_print_space = 0;
	if (num_sum == sum && count_no_index != len)
	{
		i = 0;
		while (i < len)
		{
			if (i == arr_index[i])
			{
				if (should_print_space)
				{
					printf(" ");
					should_print_space = 0;
				}
				printf("%d", arr_num[i]);
				should_print_space = 1;
			}
			i++;
		}
		printf("\n");
	}
}

void all_combinations(int *arr_index, int index, int len, int sum, int *arr_num)
{
	if (index == len)
	{
		check_sum(arr_index, len, sum, arr_num);
		return ;
	}
	arr_index[index] = index;
	all_combinations(arr_index, index+1, len, sum, arr_num);
	arr_index[index] = -1;
	all_combinations(arr_index, index+1, len, sum, arr_num);
}

int main(int ac, char **av)
{
	int sum;
	int len;
	int *arr_num;
	int *arr_index;
	int i;

	if (ac < 3)
		return (1);

	sum = atoi(av[1]);
	// printf("sum = %d\n", sum);
	len = ac - 2;
	arr_num = malloc(sizeof(int) * len);
	arr_index = malloc(sizeof(int) * len);
	if (!arr_num || !arr_index)
		return(1);

	i = 0;
	while (i < len)
	{
		arr_num[i] = atoi(av[i+2]);
		arr_index[i] = 0;
		i++;
	}
	all_combinations(arr_index, 0, len, sum, arr_num);
}