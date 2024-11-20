/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abboudje <abboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 21:27:46 by abboudje          #+#    #+#             */
/*   Updated: 2024/06/17 07:19:19 by abboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_append(char *text, char *buffer)
{
	char	*new_text;

	new_text = ft_strjoin(text, buffer);
	return (free(text), new_text);
}

char	*get_the_line(char *text)
{
	char	*line;
	size_t	line_len;
	size_t	i;

	line_len = 0;
	if (!text)
		return (NULL);
	if (*text == '\0')
		return (text = NULL, NULL);
	while (text[line_len] && text[line_len] != '\n')
		line_len++;
	line = ft_calloc((line_len + 2), sizeof(char));
	if (!line)
		return (free(text), text = NULL, NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		line[i] = text[i];
		i++;
	}
	if (text[i] && text[i] == '\n')
	line[i] = '\n';
	return (line);
}

char	*clean_rest_line(char	*text)
{
	int		i;
	int		j;
	int		len_rest;
	char	*rest;

	i = 0;
	if (!text)
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i])
		return (free(text), text = NULL, NULL);
	len_rest = ft_strlen(text) - i;
	rest = malloc((len_rest + 1) * sizeof(char));
	if (!rest)
		return (free(text), text = NULL, NULL);
	j = 0;
	while (text[++i])
		rest[j++] = text[i];
	rest[j] = '\0';
	free(text);
	return (rest);
}

char	*get_the_text(char *text, int fd)
{
	char		*buffer;
	int			data_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(text), NULL);
	data_bytes = 1;
	while (data_bytes)
	{
		data_bytes = read(fd, buffer, BUFFER_SIZE);
		if (data_bytes == -1)
			return (free(buffer), free(text), NULL);
		buffer[data_bytes] = '\0';
		text = ft_append(text, buffer);
		if (!text)
			return (free(buffer), NULL);
		if (ft_strchr(text, '\n'))
			break ;
	}
	free(buffer);
	return (text);
}

char	*get_next_line(int fd)
{
	static char	*text = NULL;
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text = get_the_text(text, fd);
	if (!text)
		return (NULL);
	new_line = get_the_line(text);
	if (!new_line)
		return (free(text), text = NULL, NULL);
	text = clean_rest_line(text);
	return (new_line);
}

/*  #include <stdio.h>
  int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		i;
	 
	if (ac != 2)
		return (-1);
	fd = open(av[1], O_RDONLY);
	i = 0;
	while (i < 3)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
} */