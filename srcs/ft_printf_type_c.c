/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:34:07 by vmaricru          #+#    #+#             */
/*   Updated: 2021/01/22 16:37:05 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_type_c_m_zero(t_data **lst, char argm)
{
	while ((*lst)->width--)
	{
		if ((*lst)->flag_zero == 0)
			ft_putchar_fd(' ', 1);
		else if ((*lst)->flag_zero == 1)
			ft_putchar_fd('0', 1);
		(*lst)->check++;
	}
	ft_putchar_fd(argm, 1);
}

void		ft_print_type_c_m_one(t_data **lst, char argm)
{
	ft_putchar_fd(argm, 1);
	while ((*lst)->width--)
	{
		ft_putchar_fd(' ', 1);
		(*lst)->check++;
	}
}

int			ft_printf_type_c(t_data **lst)
{
	char	argm;

	if ((*lst)->type == 'c')
		argm = va_arg((*lst)->arg, int);
	else if ((*lst)->type == '%')
		argm = '%';
	(*lst)->width--;
	if ((*lst)->flag_minus == 1)
		(*lst)->flag_zero = 0;
	if ((*lst)->width > 0 && (*lst)->flag_minus == 0)
	{
		ft_printf_type_c_m_zero(lst, argm);
	}
	else if ((*lst)->width > 0 && (*lst)->flag_minus == 1)
	{
		ft_print_type_c_m_one(lst, argm);
	}
	else
		ft_putchar_fd(argm, 1);
	(*lst)->check++;
	return (0);
}
