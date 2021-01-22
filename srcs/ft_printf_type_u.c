/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:39:53 by vmaricru          #+#    #+#             */
/*   Updated: 2021/01/22 16:40:59 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf_type_u(t_data **lst)
{
	char			*str;
	unsigned int	nmb;
	int				len;
	int				check_m;
	char			*str_cl;

	check_m = 1;
	nmb = va_arg((*lst)->arg, unsigned int);
	if (!(str = ft_itoa_unsigned(nmb)))
		return (-1);
	str_cl = str;
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
