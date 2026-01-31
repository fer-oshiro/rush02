/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 10:27:19 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/01/31 12:20:01 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HEADER_H
# define HEADER_H

#include <unistd.h>
#include <fcntl.h> 
#include <stdlib.h>

// apagar lib printf
#include <stdio.h>

void	ft_error_input(void);
void	ft_error_dict(void);
int		ft_arg_validation(int argc, char **argv);
char 	*ft_file_name(int argc, char **argv);
int 	ft_str_to_int(int argc, char **argv);
void 	ft_read_file(char *file);

typedef struct s_translate 
{
	char *number;
	char *extensive;
} t_translate;

#endif