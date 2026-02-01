/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 10:27:19 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/02/01 15:55:39 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

// apagar lib printf
# include <stdio.h>

typedef struct s_translate
{
	char	*number;
	char	*extensive;
	int		size;
}			t_translate;

void		ft_error_input(void);
void		ft_error_dict(void);
int			ft_arg_validation(int argc, char **argv);
char		*ft_file_name(int argc, char **argv);
char		*ft_str_to_int(int argc, char **argv);
int			ft_find_char(char *str, char find);
int			ft_is_space(char str);
int			ft_str_len_space(char *str, char sep);
int			ft_number_validation(char *str);
int			ft_number_ext_validation(char *str);
int			ft_str_num_ext_fullsize(char *str);
int			ft_str_len(char *str);
char		*ft_extract_number_ext(char *str);
void		ft_bzero_char(void *s, size_t n);
void		ft_bzero_int(void *s, size_t n);
void		ft_clean_dict(t_translate *translate_store);
t_translate	*ft_read_file(char *file);
void		ft_sort_dict(t_translate *store, int size);
char		*ft_get_word(t_translate *dict, char *number);
int			ft_strcmp(char *s1, char *s2);
void		solve(char *num, t_translate *dict, int *g_first);
void		ft_print_3_digits(char *num, t_translate *dict);
void		ft_print_expanded(char *num, t_translate *dict);
int			ft_putstr(char *str);
void		ft_len_1(t_translate *dict, char num, int *g_first);
void		ft_len_2(t_translate *dict, char num, int *g_first);
void		ft_len_3(t_translate *dict, char num, int *g_first);
void		ft_print_word(char *word, int *g_first);
void		ft_print_zeros(int len, int f_len, t_translate *dict, int *g_f);

#endif