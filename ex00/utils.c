/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 09:21:38 by lpedro-s          #+#    #+#             */
/*   Updated: 2026/02/01 10:20:50 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_is_space(char str)
{
	return (str <= ' ' || str == 127);
}

int	ft_str_len_space(char *str, char sep)
{
	int	len;

	len = 0;
	while (*str && *str != sep && *str != ' ')
	{
		len++;
		str++;
	}
	return (len);
}

int	ft_str_len(char *str)
{
	int	len;
	len = 0;

	if (!str)
		return (0);
	
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

int	ft_find_char(char *str, char find)
{
	while (*str)
	{
		if (*str == find)
			return (1);
		str++;
	}
	return (0);
}

int	ft_str_num_ext_fullsize(char *str)
{
	int	index;
	int	i;

	i = 0;
	index = 0;
	while (str[i])
	{
		if (str[i] == ':')
			break ;
		i++;
	}
	i++;
	while (str[i])
	{
		i++;
		index++;
	}
	return (index);
}
