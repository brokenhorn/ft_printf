/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:13:47 by vmaricru          #+#    #+#             */
/*   Updated: 2021/01/22 16:16:23 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_type_s_null(t_data **lst, int len)
{
	char	*s;

	s = "(null)";
	while (len > 0 && s != '\0')
	{
		ft_putchar_fd(*s, 1);
		s++;
		(*lst)->check++;
		len--;
	}
}

void		ft_printf_type_s_print(t_data **lst, int len, char **str)
{
	if ((*lst)->flag_minus == 1)
		(*lst)->flag_zero = 0;
	if ((*lst)->flag_minus == 1)
	{
		ft_printf_utils_len_put(len, str, lst);
		ft_printf_utils_print_space(lst);
	}
	else if ((*lst)->flag_zero == 1)
	{
		ft_printf_utils_print_zero(lst);
		ft_printf_utils_len_put(len, str, lst);
	}
	else
	{
		ft_printf_utils_print_space(lst);
		ft_printf_utils_len_put(len, str, lst);
	}
}

int			ft_printf_type_s(t_data **lst)
{
	int		len;
	char	*str;

	str = va_arg((*lst)->arg, char*);
	len = ft_strlen(str);
	if (!str)
		len = 6;
	if ((*lst)->accuracy < len && (*lst)->accuracy >= 0)
		len = ((*lst)->accuracy);
	if ((*lst)->width > 0)
		(*lst)->width -= len;
	ft_printf_type_s_print(lst, len, &str);
	return (0);
}
