/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 09:11:49 by lpedro-s          #+#    #+#             */
/*   Updated: 2026/02/01 15:59:10 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	count_lines(char *file)
{
	char	c;
	int		bytes;
	int		current_line;
	int		fd;

	fd = open(file, O_RDONLY);
	current_line = 0;
	bytes = read(fd, &c, 1);
	while (bytes > 0)
	{
		if (c == '\n')
			current_line++;
		bytes = read(fd, &c, 1);
	}
	close(fd);
	return (current_line);
}

char	*read_line(int fd)
{
	char	*line;
	char	c;
	int		i;
	int		bytes;

	line = malloc(1000);
	i = 0;
	if (!line)
		return (NULL);
	bytes = read(fd, &c, 1);
	while (bytes > 0)
	{
		line[i++] = c;
		if (c == '\n')
			break ;
		bytes = read(fd, &c, 1);
	}
	if (bytes <= 0 && i == 0)
	{
		free(line);
		return (NULL);
	}
	line[i] = '\0';
	return (line);
}

char	*ft_extract_number(char *str)
{
	char	*number;
	int		len;
	int		index;

	if (!ft_number_validation(str))
		return (NULL);
	len = ft_str_len_space(str, ':');
	number = (char *)malloc((len + 1) * sizeof(char));
	if (!number)
		return (NULL);
	index = 0;
	while (*str != ':')
	{
		if (*str >= '0' && *str <= '9')
		{
			number[index] = *str;
			index++;
		}
		str++;
	}
	number[index] = '\0';
	return (number);
}

t_translate	ft_parse_line(char *str)
{
	t_translate	entry;

	if (!ft_find_char(str, ':'))
	{
		entry.number = NULL;
		return (entry);
	}
	entry.number = ft_extract_number(str);
	entry.extensive = ft_extract_number_ext(str);
	entry.size = ft_str_len(entry.number);
	return (entry);
}

t_translate	*ft_read_file(char *file)
{
	int			fd;
	int			total;
	int			j;
	char		*line;
	t_translate	*store;

	total = count_lines(file);
	store = malloc((total + 1) * sizeof(t_translate));
	fd = open(file, O_RDONLY);
	j = 0;
	if (!store || fd < 0)
		return (NULL);
	while (j < total)
	{
		line = read_line(fd);
		if (!line)
			break ;
		store[j] = ft_parse_line(line);
		free(line);
		if (!store[j].number || !store[j++].extensive)
			break ;
	}
	close(fd);
	if (j < total)
		return (ft_clean_dict(store), NULL);
	return (ft_sort_dict(store, total), store);
}