/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:45:50 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/02/01 15:58:05 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_len_3(t_translate *dict, char num, int *g_first)
{
	char	d[2];

	d[0] = num;
	d[1] = '\0';
	ft_print_word(ft_get_word(dict, d), g_first);
	ft_print_word(ft_get_word(dict, "100"), g_first);
}

void	ft_len_2(t_translate *dict, char num, int *g_first)
{
	char	tens[3];

	tens[0] = num;
	tens[1] = '0';
	tens[2] = '\0';
	ft_print_word(ft_get_word(dict, tens), g_first);
}

void	ft_len_1(t_translate *dict, char num, int *g_first)
{
	char	d[2];

	d[0] = num;
	d[1] = '\0';
	ft_print_word(ft_get_word(dict, d), g_first);
}
