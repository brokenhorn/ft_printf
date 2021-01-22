/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_minus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:08:43 by vmaricru          #+#    #+#             */
/*   Updated: 2021/01/22 16:09:06 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_minus(int check_m, int nmb, t_data **lst)
{
	if (nmb < 0)
	{
		check_m = 0;
		nmb *= -1;
		(*lst)->width--;
	}
	return (check_m);
}
