/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:16:43 by vmaricru          #+#    #+#             */
/*   Updated: 2021/01/22 16:22:01 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_utils_len_put(int len, char **str, t_data **lst)
{
	if (!(*str))
	{
		ft_printf_type_s_null(lst, len);
		return ;
	}
	while (len != 0 && **str != '\0')
	{
		ft_putchar_fd(**str, 1);
		len--;
		(*str)++;
		(*lst)->check++;
	}
}

void	ft_printf_utils_check_m(int check_m)
{
	if (check_m == 0)
		ft_putchar_fd('-', 1);
}

void	ft_printf_utils_print_space(t_data **lst)
{
	while ((*lst)->width > 0)
	{
		ft_putchar_fd(' ', 1);
		(*lst)->width--;
		(*lst)->check++;
	}
}

void	ft_printf_utils_print_zero(t_data **lst)
{
	while ((*lst)->width > 0)
	{
		ft_putchar_fd('0', 1);
		(*lst)->width--;
		(*lst)->check++;
	}
}

void	ft_printf_type_d_print_i(t_data **lst, int i)
{
	while (i--)
	{
		ft_putchar_fd('0', 1);
		(*lst)->check++;
	}
}
