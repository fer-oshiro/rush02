/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 11:11:41 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/02/01 11:47:24 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int g_first = 1; // Variável global para controlar espaços

void	ft_print_word(char *word)
{
	if (!word)
		return ;
	if (!g_first)
		write(1, " ", 1);
	ft_putstr(word);
	g_first = 0;
}

char	*ft_get_word(t_translate *dict, char *num)
{
	int i = 0;
	while (dict[i].number)
	{
		if (ft_strcmp(dict[i].number, num) == 0)
			return (dict[i].extensive);
		i++;
	}
	return (NULL);
}

// Lida com grupos de até 3 dígitos (ex: "123")
void	handle_3_digits(char *num, t_translate *dict)
{
	int len = 0;
	while (num[len]) len++;

	if (len == 3 && num[0] != '0')
	{
		char d[2] = {num[0], '\0'};
		ft_print_word(ft_get_word(dict, d));
		ft_print_word(ft_get_word(dict, "100"));
		num++; // pula para as dezenas
		len--;
	}
	if (len == 2 && num[0] == '1') // 10-19
	{
		ft_print_word(ft_get_word(dict, num));
		return ;
	}
	if (len == 2 && num[0] != '0') // 20-99
	{
		char tens[3] = {num[0], '0', '\0'};
		ft_print_word(ft_get_word(dict, tens));
		num++;
		len--;
	}
	if (len == 1 && num[0] != '0') // 1-9
	{
		char d[2] = {num[0], '\0'};
		ft_print_word(ft_get_word(dict, d));
	}
}

void	solve(char *num, t_translate *dict)
{
	int len = 0;
	while (num[len]) len++;
	
	if (len == 0) return ;
	if (ft_strcmp(num, "0") == 0) {
		ft_print_word(ft_get_word(dict, "0"));
		return ;
	}

	int first_len = len % 3;
	if (first_len == 0) first_len = 3;

	char prefix[4] = {0};
	int i = 0;
	while (i < first_len) {
		prefix[i] = num[i];
		i++;
	}

	// Se o grupo não for "000", processa ele e a potência
	if (ft_strcmp(prefix, "000") != 0)
	{
		handle_3_digits(prefix, dict);
		if (len > 3)
		{
			// Achar potência: '1' seguido de (len - first_len) zeros
			int power_size = len - first_len + 1;
			int k = 0;
			while (dict[k].number)
			{
				if (dict[k].size == power_size && dict[k].number[0] == '1')
				{
					ft_print_word(dict[k].extensive);
					break ;
				}
				k++;
			}
		}
	}
	
	char *rest = num + first_len;
	while (*rest == '0') rest++; // Pula blocos de zero
	if (*rest) solve(rest, dict);
}