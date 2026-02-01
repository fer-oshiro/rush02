/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 09:11:49 by lpedro-s          #+#    #+#             */
/*   Updated: 2026/02/01 09:44:53 by fsayuri-         ###   ########.fr       */
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
		return ("");
	len = ft_str_len_space(str, ':');
	number = (char *)malloc((len + 1) * sizeof(char));
	if (!number)
		return ("");
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

int	ft_read_file(char *file)
{
	int			fd;
	int			total_lines;
	t_translate	*translate_store;
	int			j;
	char	*line;

	total_lines = count_lines(file);
	translate_store = (t_translate *)malloc((total_lines + 1)
			* sizeof(t_translate));
	fd = open(file, O_RDONLY);
	j = 0;
	while (j < total_lines)
	{
		line = read_line(fd);
		if (!line)
		{
			close(fd);
			return (0);
		}
		translate_store[j] = ft_parse_line(line);
		free(line);
		if (translate_store[j].number[0] == '\0'
			|| translate_store[j].extensive == NULL)
		{
			close(fd);
			return (0);
		}
		j++;
	}
	close(fd);
	return (1);
}
