/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:37:28 by vmaricru          #+#    #+#             */
/*   Updated: 2021/01/22 16:39:20 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_str_toupper(char *str)
{
	int				i;

	i = 0;
	while (*(str + i) != '\0')
	{
		*(str + i) = ft_toupper(str[i]);
		i++;
	}
}

int					ft_printf_type_x(t_data **lst)
{
	char			*str;
	unsigned int	nmb;
	int				len;
	int				check_m;
	char			*str_cl;

	check_m = 1;
	nmb = va_arg((*lst)->arg, unsigned int);
	if (!(str = ft_itoa_based(nmb, 16)))
		return (-1);
	str_cl = str;
	if ((*lst)->type == 'X')
		ft_str_toupper(str);
	if (nmb == 0 && (*lst)->accuracy != -1)
		*str = 0;
	len = ft_strlen(str);
	if ((*lst)->width > 0)
		(*lst)->width -= len;
	if ((*lst)->accuracy >= 0)
		ft_printf_type_d_print_accuracy(&str, lst, len, check_m);
	else
		ft_printf_type_d_print(&str, lst, len, check_m);
	free(str_cl);
	return (0);
}
