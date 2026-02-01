/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 09:48:24 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/02/01 13:42:20 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_clean_dict(t_translate *translate_store)
{
	int	i;

	if (!translate_store)
		return ;
	i = 0;
	while (!translate_store[i].number && !translate_store[i].extensive)
	{
		if (translate_store[i].number != NULL)
			free(translate_store[i].number);
		if (translate_store[i].extensive != NULL)
			free(translate_store[i].extensive);
		i++;
	}
	free(translate_store);
}
