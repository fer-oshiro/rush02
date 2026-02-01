/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 10:25:59 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/02/01 17:05:42 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	int			g_first;
	char		*file;
	char		*num;
	t_translate	*translate_store;

	g_first = 1;
	if (!ft_arg_validation(argc, argv))
	{
		ft_error_input();
		return (0);
	}
	file = ft_file_name(argc, argv);
	num = ft_str_to_int(argc, argv);
	translate_store = ft_read_file(file);
	if (!translate_store)
	{
		ft_error_dict();
		return (0);
	}
	if (validate(num, translate_store))
		solve(num, translate_store, &g_first);
	else
		ft_error_dict();
}
