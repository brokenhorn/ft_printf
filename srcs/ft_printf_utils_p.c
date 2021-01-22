/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_p.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:19:30 by vmaricru          #+#    #+#             */
/*   Updated: 2021/01/22 17:21:40 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_utils_p_acc_else(t_data **lst, char **str, int len)
{
	ft_printf_utils_print_space(lst);
	ft_putstr_fd("0x", 1);
	if ((*lst)->accuracy != 0 && **str != '0')
		ft_printf_utils_len_put(len, str, lst);
}

void	ft_printf_utils_p_acc_if_m_zero(t_data **lst,
		char **str, int len, int i)
{
	i = **str == '0' ? i + 1 : i;
	ft_printf_type_p_print_accuracy0(lst, i);
	if ((*lst)->accuracy != 0 && **str != '0')
		ft_printf_utils_len_put(len, str, lst);
}
