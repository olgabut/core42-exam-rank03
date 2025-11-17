
#include <stdio.h>

void sort(char *result)
{
	int i, j;
	char tmp;
	char *str;

	str = result;
	if (!str)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		j= i+1;
		while (str[j] != '\0')
		{
			if (str[i] > str[j])
			{
				tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}
			j++;
		}
		i++;
	}
	// *result = str;
}

int len_str(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
int find_first(char *str, int len)
{
	int i;
	i = len - 2;
	while (i >= 0)
	{
		if (str[i] < str[i+1])
			return (i);
		else
			i--;
	}
	return (i);
}
int find_min(char *substr)
{
	int i;
	int min_index;

	i = 1;
	min_index = 1;
	while(substr[i] != '\0')
	{
		if (substr[0] < substr[i] && substr[i] < substr[min_index])
			min_index = i;
		i++;
	}
	return min_index;
}

int next_permutation(char *str, int len)
{
	int i, j;
	char tmp;
	int min;

	i = find_first(str, len);
	if (i < 0)
		return (0);
	j = i+find_min(str+i);
	
	tmp = str[i];
	str[i] = str[j];
	str[j] = tmp;
	
	// printf("i = %d, j = %d\n", i, j);
	// printf("before = '%s'\n", str);
	sort(str+i+1);
	// printf("after = '%s'\n", str);
	return (1);
}

int main(int ac, char **av)
{
	char *input;
	int len;

	if (ac != 2)
		return (1);
	input = av[1];
	// printf("input = '%s'\n", input);
	sort(input);
	printf("%s\n", input);
	len = len_str(input);

	while (next_permutation(input, len))
	{  
		printf("%s\n", input);
	}
	return (0);
}