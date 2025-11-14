
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list
{
	char c;
	struct s_list *next;
} t_list;



int save_to_list(t_list **head, char c)
{
	t_list *new_node;
	t_list *node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc problem");
		return 0;
	}
	new_node->c = c;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (1);
	}
	node = *head;
	while (node->next)
		node = node->next;
	node->next = new_node;
	return (1);
}

void print_list(t_list *node)
{
	while (node)
	{
		printf("%c", node->c);
		node = node->next;
	}
}
void free_list(t_list *node)
{
	t_list *tmp;

	while (node)
	{
		tmp = node->next;
		free(node);
		node = NULL;
		node = tmp;
	}
}

int equal_word(t_list *node, char *word)
{
	int i;

	i = 0;
	while (node && word[i] != '\0')
	{
		if (node->c != word[i])
			return (0);
		node = node->next;
		i++;
	}
	if (i != strlen(word))
		return 0;
	return 1;
}

void replace_word(t_list **head, char *word)
{
	t_list *cur;
	int i;

	cur = *head;
	while (cur)
	{
		if (equal_word(cur, word))
		{
			i = strlen(word);
			while (i > 0)
			{
				cur->c = '*';
				cur = cur->next;
				i--;
			}
		}
		else
		{
			cur = cur->next;
		}
	}
}

int main(int ac, char **av)
{
	char *search = NULL;
	char buffer;
	int read_b;
	t_list *stdin_list = NULL;

	if (ac != 2)
		return (1);

	search = av[1];
	// printf("we should find all '%s'\n", search);

	read_b = 1;
	while (read_b)
	{
		read_b = read(0, &buffer, 1);
		if (read_b == -1)
		{
			fprintf(stderr, "Error: read problem");
			free_list(stdin_list);
			return (1);
		}
		if (read_b > 0)
			if (!save_to_list(&stdin_list, buffer))
			{
				free_list(stdin_list);
				return (1);
			}
	}
	
	replace_word(&stdin_list, search);
	print_list(stdin_list);
	return (0);
}