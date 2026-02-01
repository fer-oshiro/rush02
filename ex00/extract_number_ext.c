/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_number_ext.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 09:09:45 by lpedro-s          #+#    #+#             */
/*   Updated: 2026/02/01 11:24:03 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_start_index(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == ':')
			break ;
		index++;
	}
	index++;
	while (str[index])
	{
		if (!ft_is_space(str[index]))
			break ;
		index++;
	}
	return (index);
}

char	*ft_extract_number_ext(char *str)
{
	char	*number_ext;
	int		index;
	int		index_start;
	int		index_end;

	if (!ft_number_ext_validation(str))
		return (NULL);
	index_start = ft_start_index(str);
	index = ft_str_len(str);
	while (ft_is_space(str[index]))
		index--;
	index_end = index + 1;
	number_ext = (char *)malloc((index_end - index_start + 1) * sizeof(char));
	index = 0;
	while (index < ((index_end - index_start + 1)))
	{
		number_ext[index] = str[index_start + index];
		index++;
	}
	number_ext[index - 1] = '\0';
	return (number_ext);
}
