

#include <stdio.h>
#include <unistd.h>

int unmatched_count(char *str)
{
	int i;
	int open_bracket;
	int close_bracket;

	i = 0;
	open_bracket = 0;
	close_bracket = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '(')
			open_bracket++;
		if (str[i] == ')')
		{
			if (open_bracket > 0)
				open_bracket--;
			else
				close_bracket++;
		}
		i++;
	}
	return (open_bracket + close_bracket);
}

int count_space(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			count++;
		i++;
	}
	return (count);
}

void	print_solutions(char *str, int index, char *buffer, int min_spaces)
{
	char c;
	c = str[index];
	if (c == '\0')
	{
		buffer[index] = '\0';
		if (count_space(buffer) == min_spaces
			&& unmatched_count(buffer) == 0)
		{
			puts(buffer);
		}
		return ;
	}
	if (c == '(' || c == ')')
	{
		buffer[index] = c;
		print_solutions(str, index+1, buffer, min_spaces);
	}
	buffer[index]= '.';
	print_solutions(str, index+1, buffer, min_spaces);
}




int main(int ac, char **av)
{
	char *str;
	int min_spaces;
	int len;
	char buffer[256];

	if (ac != 2)
		return (1);
	str = av[1];
	min_spaces = unmatched_count(str);
	printf("min = %d\n", min_spaces);
	print_solutions(str, 0, buffer, min_spaces);
	return(0);
}