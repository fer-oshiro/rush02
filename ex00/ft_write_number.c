/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:48:22 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/02/01 15:49:14 by fsayuri-         ###   ########.fr       */
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

void	ft_print_zeros(int len, int first_len, t_translate *dict, int *g_first)
{
	int	k;
	int	power_size;

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
