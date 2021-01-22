/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:26:14 by vmaricru          #+#    #+#             */
/*   Updated: 2021/01/22 16:33:48 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf_arg(t_data **lst)
{
	if ((*lst)->type == 'c' || (*lst)->type == '%')
		ft_printf_type_c(lst);
	else if ((*lst)->type == 's')
		ft_printf_type_s(lst);
	else if ((*lst)->type == 'd' || (*lst)->type == 'i')
	{
		if ((ft_printf_type_d(lst)) == -1)
			return (-1);
	}
	else if ((*lst)->type == 'u')
	{
		if ((ft_printf_type_u(lst)) == -1)
			return (-1);
	}
	else if ((*lst)->type == 'p')
	{
		if ((ft_printf_type_p(lst)) == -1)
			return (-1);
	}
	else if ((*lst)->type == 'x' || (*lst)->type == 'X')
	{
		if ((ft_printf_type_x(lst)) == -1)
			return (-1);
	}
	return (0);
}

const char		*ft_printf_parse(const char **format, t_data **lst)
{
	*format = ++(*format);
	while (**format == '0' || **format == '-')
		*format = ft_parse_flag((char*)*format, lst);
	*format = ft_parse_width((char*)*format, lst);
	*format = ft_parse_accuracy((char*)*format, lst);
	*format = ft_parse_type((char*)*format, lst);
	return (*format);
}

int				ft_printf_print(const char **format, t_data **lst)
{
	while (**format != '\0')
	{
		if (**format != '%')
		{
			ft_putchar_fd(**format, 1);
			*format += 1;
			(*lst)->check++;
		}
		else
		{
			*format = ft_printf_parse(format, lst);
			if (ft_printf_arg(lst) == -1)
				return (-1);
			ft_lst_re(*lst);
		}
	}
	return (0);
}

int				ft_printf(const char *format, ...)
{
	t_data		*lst;
	int			check;

	if (!(lst = ft_lst_dec()))
		return (-1);
	va_start(lst->arg, format);
	if (ft_printf_print(&format, &lst) == -1)
		lst->check = -1;
	va_end(lst->arg);
	check = lst->check;
	free(lst);
	return (check);
}
