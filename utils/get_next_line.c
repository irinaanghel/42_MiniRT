#include "../includes/utils.h"

char	*gnl_line_return(char **str, int i)
{
	char	*res;

	gnl_substr(&res, str, 0, ++i);
	*str = gnl_strdup(&(*str), i);
	return (res);
}

char	*gnl_no_read(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*gnl_buffer_not_empty(char **str, int i)
{
	char	*res;

	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if ((*str)[i] == '\n')
		return (gnl_line_return(&(*str), i));
	if ((*str)[i] == '\0')
	{
		gnl_substr(&res, str, 0, ++i);
		free(*str);
		*str = NULL;
		return (res);
	}
	return (NULL);
}

char	*gnl_read_loop(int fd, char **str)
{
	int		i;
	int		nbread;
	char	buffer[BUFFER_SIZE + 1];

	i = 0;
	while (1)
	{
		gnl_bzero(buffer, (BUFFER_SIZE + 1) * sizeof(char));
		nbread = read(fd, buffer, BUFFER_SIZE);
		*str = gnl_strjoin(&(*str), buffer);
		if (nbread > 0)
		{
			while ((*str)[i] && (*str)[i] != '\n')
				i++;
			if ((*str)[i] == '\n')
				return (gnl_line_return(&(*str), i));
		}
		else if ((*str)[0] == '\0')
			return (gnl_no_read(&(*str)));
		else
			return (gnl_buffer_not_empty(&(*str), i));
	}
}

char	*get_next_line(int fd)
{
	static char	*str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!str)
	{
		str = malloc(1 * sizeof(char));
		gnl_bzero(str, 1 * sizeof(char));
	}
	return (gnl_read_loop(fd, &str));
}
