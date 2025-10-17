#include "get_next_line_bonus.h"

char	*extract_line(char const *leftover)
{
	char	*line;
	size_t	len;
	size_t	i;

	if (leftover == NULL || *leftover == '\0')
		return (NULL);
	len = 0;
	while (leftover[len] && leftover[len] != '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = leftover[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_leftover(char *leftover)
{
	char	*new;
	char	*newline_ptr;
	size_t	len;

	if (leftover == NULL)
		return (NULL);
	newline_ptr = ft_strchr(leftover, '\n');
	if (newline_ptr == NULL)
	{
		free(leftover);
		return (NULL);
	}
	len = ft_strlen(newline_ptr + 1);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
	{
		free(leftover);
		return (NULL);
	}
	ft_strlcpy(new, newline_ptr + 1, len + 1);
	free(leftover);
	return (new);
}

static int	read_one_line(int fd, char **leftover)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	read_bytes;

	while (ft_strchr(*leftover, '\n') == NULL)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(*leftover);
			*leftover = NULL;
			return (-1);
		}
		if (read_bytes == 0)
			return (0);
		buf[read_bytes] = '\0';
		*leftover = gnl_strjoin(*leftover, buf);
		if (*leftover == NULL)
			return (-1);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*leftover[FOPEN_MAX];
	char		*tmp;
	int			status;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 || fd >= FOPEN_MAX)
		return (-1);
	status = read_one_line(fd, &leftover[fd]);
	if (status <= 0 && (leftover[fd] == NULL || *leftover[fd] == '\0'))
	{
		free(leftover[fd]);
		leftover[fd] = NULL;
		return (0);
	}
	*line = extract_line(leftover[fd]);
	tmp = update_leftover(leftover[fd]);
	leftover[fd] = tmp;
	if (*line == NULL)
	{
		free(leftover[fd]);
		leftover[fd] = NULL;
		return (-1);
	}
	return (1);
}
