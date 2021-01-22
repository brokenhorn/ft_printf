/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:13:12 by vmaricru          #+#    #+#             */
/*   Updated: 2021/01/22 17:49:28 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_printf_type_p_print_accuracy1(t_data **lst,
		int len, int i, char **str)
{
	(*lst)->width -= i;
	ft_printf_type_d_print_i(lst, i);
	ft_printf_utils_len_put(len, str, lst);
	ft_printf_utils_print_space(lst);
}

void				ft_printf_type_p_print_accuracy0(t_data **lst, int i)
{
	(*lst)->width -= i;
	ft_printf_utils_print_space(lst);
	ft_putstr_fd("0x", 1);
	ft_printf_type_d_print_i(lst, i);
}

void				ft_printf_type_p_print_accuracy(char **str,
		t_data **lst, int len)
{
	int				i;

	i = (*lst)->accuracy - len + 2;
	if ((*lst)->accuracy == 0)
	{
		ft_printf_utils_print_space(lst);
		ft_putstr_fd("0x", 1);
		return ;
	}
	if ((*lst)->flag_minus == 1)
	{
		ft_putstr_fd("0x", 1);
		if ((*lst)->accuracy >= len)
			ft_printf_type_p_print_accuracy1(lst, len, i, str);
	}
	else if ((*lst)->flag_minus == 0 && (*lst)->accuracy >= len)
	{
		if ((*lst)->accuracy >= len)
		{
			ft_printf_utils_p_acc_if_m_zero(lst, str, len, i);
		}
	}
	else
		ft_printf_utils_p_acc_else(lst, str, len);
}

void				ft_printf_type_p_print(char **str, t_data **lst, int len)
{
	if ((*lst)->flag_minus == 1 || (*lst)->accuracy > -1)
		(*lst)->flag_zero = 0;
	if ((*lst)->flag_minus == 1)
	{
		ft_putstr_fd("0x", 1);
		ft_printf_utils_len_put(len, str, lst);
		ft_printf_utils_print_space(lst);
	}
	else if ((*lst)->flag_zero == 1)
	{
		ft_putstr_fd("0x", 1);
		ft_printf_utils_print_zero(lst);
		ft_printf_utils_len_put(len, str, lst);
	}
	else
	{
		ft_printf_utils_print_space(lst);
		ft_putstr_fd("0x", 1);
		ft_printf_utils_len_put(len, str, lst);
	}
}

int					ft_printf_type_p(t_data **lst)
{
	long long int	pnmb;
	char			*str;
	int				len;
	char			*cln;

	pnmb = va_arg((*lst)->arg, long);
	if (!(str = ft_itoa_based(pnmb, 16)))
		return (-1);
	len = ft_strlen(str) + 2;
	cln = str;
	if ((*lst)->accuracy == 0 && pnmb == 0)
		len = 2;
	if ((*lst)->width > 0)
		(*lst)->width -= len;
	if ((*lst)->accuracy >= 0)
		ft_printf_type_p_print_accuracy(&str, lst, len);
	else
		ft_printf_type_p_print(&str, lst, len);
	(*lst)->check += 2;
	free(cln);
	return (0);
}
