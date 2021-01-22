/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:09:29 by vmaricru          #+#    #+#             */
/*   Updated: 2021/01/22 16:12:11 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lst_re(t_data *lst)
{
	(lst)->flag_zero = 0;
	(lst)->flag_minus = 0;
	(lst)->width = 0;
	(lst)->accuracy = -1;
	(lst)->type = 0;
}

t_data	*ft_lst_dec(void)
{
	t_data *tmp;

	tmp = (t_data*)malloc(sizeof(t_data));
	if (tmp == 0)
		return (0);
	tmp->flag_zero = 0;
	tmp->flag_minus = 0;
	tmp->width = 0;
	tmp->accuracy = -1;
	tmp->type = 0;
	tmp->check = 0;
	return (tmp);
}
