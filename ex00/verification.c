/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 11:11:41 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/02/01 17:06:00 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	handle_3_digits_validation(char *num, t_translate *dict)
{
	int	len;

	len = ft_str_len(num);
	if (len == 3 && num[0] != '0')
	{
		if (!ft_get_word(dict, (char []){num[0], 0}))
			return (0);
		num++;
		len--;
	}
	if (len == 2 && num[0] == '1')
		return (ft_get_word(dict, num) != NULL);
	if (len == 2 && num[0] != '0')
	{
		if (!ft_get_word(dict, (char []){num[0], '0', 0}))
			return (0);
		num++;
	}
	if (ft_str_len(num) == 1 && num[0] != '0')
		return (ft_get_word(dict, (char []){num[0], 0}) != NULL);
	return (1);
}

int	ft_check_zeros(int len, int first_len, t_translate *dict)
{
	int	k;
	int	p_size;

	if (len <= 3)
		return (1);
	p_size = len - first_len + 1;
	k = 0;
	while (dict[k].number)
	{
		if (dict[k].size == p_size && dict[k].number[0] == '1')
			return (1);
		k++;
	}
	return (0);
}

int	process_block_validation(char *num, int len, t_translate *dict)
{
	char	prefix[4];
	int		i;
	int		f_len;

	f_len = len % 3;
	if (f_len == 0)
		f_len = 3;
	i = -1;
	while (++i < 4)
		prefix[i] = 0;
	i = -1;
	while (++i < f_len)
		prefix[i] = num[i];
	if (ft_strcmp(prefix, "000") != 0)
	{
		if (!handle_3_digits_validation(prefix, dict))
			return (0);
		if (!ft_check_zeros(len, f_len, dict))
			return (0);
	}
	return (1);
}

int	validate(char *num, t_translate *dict)
{
	int		len;
	int		f_len;

	len = ft_str_len(num);
	if (len == 0)
		return (1);
	if (ft_strcmp(num, "0") == 0)
		return (ft_get_word(dict, "0") != NULL);
	if (!process_block_validation(num, len, dict))
		return (0);
	f_len = len % 3;
	if (f_len == 0)
		f_len = 3;
	num += f_len;
	while (*num == '0')
		num++;
	if (*num)
		return (validate(num, dict));
	return (1);
}
