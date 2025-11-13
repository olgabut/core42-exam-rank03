
#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (!src)
		return (dest);
	while (--n > 0)
		((char *)dest)[n - 1] = ((char *)src)[n - 1];
	return (dest);
}

size_t	ft_strlen(char *s)
{
	size_t	ret = 0;
	if (!s)
		return (0);
	while (s[ret] != '\0')
	{
		ret++;
	}
	return (ret);
}

int	str_append_mem(char **s1, char *s2, size_t size2)
{
	size_t	size1 = ft_strlen(*s1);
	char	*tmp = malloc(size2 + size1 + 1);
	if (!tmp)
		return (0);
	// printf("str_append_mem s1='%s'\n", *s1);
	// printf("str_append_mem s2='%s'\n", s2);
	ft_memcpy(tmp, *s1, size1 + 1);
	// printf("str_append_mem tmp='%s'\n", tmp);
	ft_memcpy(tmp + size1, s2, size2 + 1);
	// printf("str_append_mem tmp='%s'\n", tmp);
	tmp [size1 + size2] = 0;
	free(*s1);
	*s1 = tmp;
	return (1);
}

int	str_append_str(char **s1, char *s2)
{
	return (str_append_mem(s1, s2, ft_strlen(s2)));
}

void	*ft_memmove(char *dest, char *src, size_t n)
{
	int	i;
	int max;
	// printf("ft_memmove dest='%s'\n", dest);
	// printf("ft_memmove src ='%s'\n", src);
	if (dest > src)
		return (ft_memcpy(dest, src, n));
	else if (dest == src)
		return (dest);
	max = ft_strlen(src) - 1;
	i = 0;
	while (i<=max)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void ft_setzero(char *s)
{
	int i;
	
	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		s[i] = '\0';
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char	*b;
	char	*ret = NULL;
	char	*tmp = NULL;
	int	read_ret;

	read_ret = 0;
	// printf("start b = '%s'\n", b);
	if (!b)
	{
		b = malloc(BUFFER_SIZE + 1);
		b[0]= '\0';
		read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret == -1)
			return (NULL);
		
		b[read_ret] = '\0';
		// printf("read_ret=%d\n", read_ret);
	}
	// printf("b = '%s'\n", b);
	tmp = ft_strchr(b, '\n'); // pointer to '/n' char
	// printf("tmp='%s'\n", tmp);
	while (b[0] != '\0' && !tmp) // tmp = NULL
	{
		// printf("WHILE\n");
		if (!str_append_str(&ret, b))
		{
			free(b);
			b = NULL;
			return (NULL);
		}
		// printf("ret='%s'\n", ret);
	    read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret == -1)
		{
			free(b);
			b = NULL;
			return (NULL);
		}
		// printf("read_ret=%d\n", read_ret);
		if (read_ret == 0)
		{
			free(b);
			b = NULL;
			return (ret);
		}
		// printf("while b = '%s'\n", b);
		b[read_ret] = 0;
		tmp = ft_strchr(b, '\n');
		// printf("while tmp='%s'\n", tmp);
	}
	if (tmp)
	{
		if (!str_append_mem(&ret, b, tmp - b + 1))
		{
			free(ret);
			ret = NULL;
			return (NULL);
		}
		ft_memmove(b, tmp + 1, ft_strlen(tmp));
	}
	// printf("final b = '%s'\n", b);
	return (ret);
}