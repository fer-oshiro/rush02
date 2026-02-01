/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:23:25 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/02/01 19:59:14 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_is_empty_string(char *str)
{
	int	is_empty;

	is_empty = 1;
	while (*str)
	{
		if (!ft_is_space(*str))
			is_empty = 0;
		str++;
	}
	return (is_empty);
}
