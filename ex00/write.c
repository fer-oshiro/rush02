/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 11:11:41 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/02/01 15:50:05 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
	if (len == 2)
	{
		if (num[0] != '0')
			ft_len_2(dict, num[0], g_first);
		num++;
		len--;
	}
	if (len == 1 && num[0] != '0')
	{
		ft_len_1(dict, num[0], g_first);
	}
}

void	ft_first_len(int len, int *first_len)
{
	*first_len = len % 3;
	if (*first_len == 0)
		*first_len = 3;
}

void	process_block(char *num, int len, t_translate *dict, int *g_first)
{
	char	prefix[4];
	int		i;
	int		f_len;

	i = 0;
	f_len = len % 3;
	if (f_len == 0)
		f_len = 3;
	while (i < 4)
		prefix[i++] = 0;
	i = 0;
	while (i < f_len)
	{
		prefix[i] = num[i];
		i++;
	}
	if (ft_strcmp(prefix, "000") != 0)
	{
		handle_3_digits(prefix, dict, g_first);
		ft_print_zeros(len, f_len, dict, g_first);
	}
}

void	solve(char *num, t_translate *dict, int *g_first)
{
	int		len;
	int		f_len;
	char	*rest;

	len = ft_str_len(num);
	if (len == 0)
		return ;
	if (ft_strcmp(num, "0") == 0)
	{
		ft_print_word(ft_get_word(dict, "0"), g_first);
		return ;
	}
	process_block(num, len, dict, g_first);
	f_len = len % 3;
	if (f_len == 0)
		f_len = 3;
	rest = num + f_len;
	while (*rest == '0')
		rest++;
	if (*rest)
		solve(rest, dict, g_first);
}
