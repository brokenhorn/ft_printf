/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:23:00 by vmaricru          #+#    #+#             */
/*   Updated: 2021/01/22 16:26:02 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_parse_flag(char *format, t_data **lst)
{
	if (*format == '-')
	{
		(*lst)->flag_minus = 1;
		format++;
	}
	else if (*format == '0')
	{
		(*lst)->flag_zero = 1;
		format++;
	}
	return (format);
}

char		*ft_parse_width(char *format, t_data **lst)
{
	if (*format == '*')
	{
		(*lst)->width = va_arg((*lst)->arg, int);
		if ((*lst)->width < 0)
		{
			(*lst)->width *= -1;
			(*lst)->flag_minus = 1;
		}
		return (format + 1);
	}
	else if (ft_isdigit(*format))
	{
		(*lst)->width = ft_atoi(format);
		while (*format >= '0' && *format <= '9')
			format++;
		return (format);
	}
	return (format);
}

char		*ft_parse_accuracy(char *format, t_data **lst)
{
	if (*format == '.')
	{
		format++;
		if (*format == '*')
		{
			(*lst)->accuracy = va_arg((*lst)->arg, int);
			return (format + 1);
		}
		else if (ft_isdigit(*format))
		{
			(*lst)->accuracy = ft_atoi(format);
			while (*format >= '0' && *format <= '9')
				format++;
			return (format);
		}
		else
		{
			(*lst)->accuracy = 0;
			return (format);
		}
	}
	return (format);
}

char		*ft_parse_type(char *format, t_data **lst)
{
	if (*format == 'c')
		(*lst)->type = 'c';
	else if (*format == 's')
		(*lst)->type = 's';
	else if (*format == 'p')
		(*lst)->type = 'p';
	else if (*format == 'd')
		(*lst)->type = 'd';
	else if (*format == 'i')
		(*lst)->type = 'i';
	else if (*format == 'u')
		(*lst)->type = 'u';
	else if (*format == 'x')
		(*lst)->type = 'x';
	else if (*format == 'X')
		(*lst)->type = 'X';
	else if (*format == '%')
		(*lst)->type = '%';
	else
		format--;
	return (++format);
}
