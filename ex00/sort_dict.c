/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpedro-s <lpedro-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 10:31:42 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/02/01 15:47:48 by lpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_compare_numbers(t_translate a, t_translate b)
{
	if (a.size > b.size)
		return (1);
	if (a.size < b.size)
		return (-1);
	return (ft_strcmp(a.number, b.number));
}

void	ft_sort_dict(t_translate *store, int size)
{
	int			i;
	int			j;
	t_translate	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (ft_compare_numbers(store[j], store[j + 1]) > 0)
			{
				temp = store[j];
				store[j] = store[j + 1];
				store[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
