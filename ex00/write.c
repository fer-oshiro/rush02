/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 11:11:41 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/02/01 14:54:24 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print_word(char *word, int *g_first)
{
	if (!word)
		return ;
	if (!*g_first)
		write(1, " ", 1);
	ft_putstr(word);
	*g_first = 0;
}

char	*ft_get_word(t_translate *dict, char *num)
{
	int	i;

	i = 0;
	while (dict[i].number)
	{
		if (ft_strcmp(dict[i].number, num) == 0)
			return (dict[i].extensive);
		i++;
	}
	return (NULL);
}

void	ft_len_3(t_translate *dict, char num, int *g_first)
{
	char	d[2] = {num, '\0'};

	ft_print_word(ft_get_word(dict, d), g_first);
	ft_print_word(ft_get_word(dict, "100"), g_first);
}

void	ft_len_2(t_translate *dict, char num, int *g_first)
{
	char	tens[3] = {num, '0', '\0'};

	ft_print_word(ft_get_word(dict, tens), g_first);
}

void	ft_len_1(t_translate *dict, char num, int *g_first)
{
	char	d[2] = {num, '\0'};

	ft_print_word(ft_get_word(dict, d), g_first);
}

void	handle_3_digits(char *num, t_translate *dict, int *g_first)
{
	int	len;

	len = ft_str_len(num);
	if (len == 3 && num[0] != '0')
	{
		ft_len_3(dict, num[0], g_first);
		num++;
		len--;
	}
	if (len == 2 && num[0] == '1')
	{
		ft_print_word(ft_get_word(dict, num), g_first);
		return ;
	}
	if (len == 2 && num[0] != '0')
	{
		ft_len_2(dict, num[0], g_first);
		num++;
		len--;
	}
	if (len == 1 && num[0] != '0')
	{
		ft_len_1(dict, num[0], g_first);
	}
}

void	solve(char *num, t_translate *dict, int *g_first)
{
	int		len;
	int		first_len;
	char	prefix[4] = {0};
	int		i;
	int		power_size;
	int		k;
	char	*rest;

	len = ft_str_len(num);
	if (len == 0)
		return ;
	if (ft_strcmp(num, "0") == 0)
	{
		ft_print_word(ft_get_word(dict, "0"), g_first);
		return ;
	}
	first_len = len % 3;
	if (first_len == 0)
		first_len = 3;
	i = 0;
	while (i < first_len)
	{
		prefix[i] = num[i];
		i++;
	}
	if (ft_strcmp(prefix, "000") != 0)
	{
		handle_3_digits(prefix, dict, g_first);
		if (len > 3)
		{
			power_size = len - first_len + 1;
			k = 0;
			while (dict[k].number)
			{
				if (dict[k].size == power_size && dict[k].number[0] == '1')
				{
					ft_print_word(dict[k].extensive, g_first);
					break ;
				}
				k++;
			}
		}
	}
	rest = num + first_len;
	while (*rest == '0')
		rest++;
	if (*rest)
		solve(rest, dict, g_first);
}
