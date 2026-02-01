/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 09:11:49 by lpedro-s          #+#    #+#             */
/*   Updated: 2026/02/01 19:58:46 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	count_lines(char *file)
{
	int		fd;
	int		count;
	int		has_content;
	char	c;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	count = 0;
	has_content = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c != '\n' && c != ' ')
			has_content = 1;
		if (c == '\n' && has_content)
		{
			count++;
			has_content = 0;
		}
	}
	if (has_content)
		count++;
	return (close(fd), count);
}

char	*read_line(int fd)
{
	char	*line;
	char	c;
	int		i;
	int		bytes;

	line = malloc(1000);
	ft_clean_string(line);
	i = 0;
	bytes = read(fd, &c, 1);
	while (bytes > 0)
	{
		if (c != '\n')
			line[i++] = c;
		if (c == '\n' && line[0] != 0)
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

	if (!str || !ft_find_char(str, ':'))
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
	while (j < total)
	{
		line = read_line(fd);
		store[j] = ft_parse_line(line);
		if (!store[j].number || !store[j].extensive)
			break ;
		free(line);
		j++;
	}
	close(fd);
	if (j < total)
		return (ft_clean_dict(store), NULL);
	return (ft_sort_dict(store, total), store);
}
