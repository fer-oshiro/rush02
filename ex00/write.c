/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 11:11:41 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/02/01 11:21:56 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *ft_get_word(t_translate *dict, char *number)
{
    int i = 0;
    while (dict[i].number != NULL)
    {
        if (ft_strcmp(dict[i].number, number) == 0)
            return (dict[i].extensive);
        i++;
    }
    return (NULL);
}

void ft_print_expanded(char *num, t_translate *dict)
{
    int len = ft_str_len(num);

    if (len == 1 || (len == 2 && num[0] == '1')) {
        // Trata 0-9 e 10-19 (valores diretos no dicionário)
        printf("%s", ft_get_word(dict, num));
    }
    else if (len == 2) {
        // Trata 20-99: imprime "20", depois o resto "3"
        char tens[3] = {num[0], '0', '\0'};
        printf("%s ", ft_get_word(dict, tens));
        if (num[1] != '0')
            ft_print_expanded(&num[1], dict);
    }
    else if (len == 3) {
        // Trata 100-999: imprime "1", depois "100", depois o resto "23"
        char digit[2] = {num[0], '\0'};
        ft_print_expanded(digit, dict);
        printf(" %s ", ft_get_word(dict, "100"));
        if (ft_strcmp(&num[1], "00") != 0)
            ft_print_expanded(&num[1], dict);
    }
    // Para números maiores (milhares, milhões), a lógica segue o mesmo padrão de grupos de 3
}