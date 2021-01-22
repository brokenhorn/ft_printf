/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:58:36 by vmaricru          #+#    #+#             */
/*   Updated: 2021/01/22 16:07:51 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_printf_type_d_print_accuracy1(t_data **lst,
		int len, int i, char **str)
{
	(*lst)->width -= i;
	ft_printf_type_d_print_i(lst, i);
	ft_printf_utils_len_put(len, str, lst);
	ft_printf_utils_print_space(lst);
}

void			ft_printf_type_d_print_accuracy0(t_data **lst,
		int i, int check_m)
{
	(*lst)->width -= i;
	ft_printf_utils_print_space(lst);
	ft_printf_utils_check_m(check_m);
	ft_printf_type_d_print_i(lst, i);
}

void			ft_printf_type_d_print_accuracy(char **str,
		t_data **lst, int len, int check_m)
{
	int i;

	i = (*lst)->accuracy - len;
	if ((*lst)->flag_minus == 1)
	{
		ft_printf_utils_check_m(check_m);
		if ((*lst)->accuracy >= len)
			ft_printf_type_d_print_accuracy1(lst, len, i, str);
		ft_printf_utils_len_put(len, str, lst);
		if ((*lst)->accuracy < len)
			ft_printf_utils_print_space(lst);
	}
	else if ((*lst)->flag_minus == 0)
	{
		if ((*lst)->accuracy >= len)
			ft_printf_type_d_print_accuracy0(lst, i, check_m);
		if ((*lst)->accuracy < len)
		{
			ft_printf_utils_print_space(lst);
			ft_printf_utils_check_m(check_m);
		}
		ft_printf_utils_len_put(len, str, lst);
	}
}

void			ft_printf_type_d_print(char **str,
		t_data **lst, int len, int check_m)
{
	if ((*lst)->flag_minus == 1 || (*lst)->accuracy > -1)
		(*lst)->flag_zero = 0;
	if ((*lst)->flag_minus == 1)
	{
		ft_printf_utils_check_m(check_m);
		ft_printf_utils_len_put(len, str, lst);
		ft_printf_utils_print_space(lst);
	}
	else if ((*lst)->flag_zero == 1)
	{
		ft_printf_utils_check_m(check_m);
		ft_printf_utils_print_zero(lst);
		ft_printf_utils_len_put(len, str, lst);
	}
	else
	{
		ft_printf_utils_print_space(lst);
		ft_printf_utils_check_m(check_m);
		ft_printf_utils_len_put(len, str, lst);
	}
}

int				ft_printf_type_d(t_data **lst)
{
	char		*str;
	long int	nmb;
	int			len;
	int			check_m;
	char		*str_cl;

	check_m = 1;
	nmb = va_arg((*lst)->arg, int);
	check_m = ft_check_minus(check_m, nmb, lst);
	(*lst)->check = nmb < 0 ? (*lst)->check + 1 : (*lst)->check;
	nmb = nmb < 0 ? -nmb : nmb;
	if (!(str = ft_itoa(nmb)))
		return (-1);
	str_cl = str;
	if (nmb == 0 && !((*lst)->accuracy <= -1))
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
