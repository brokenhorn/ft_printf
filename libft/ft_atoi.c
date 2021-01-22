/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:46:54 by vmaricru          #+#    #+#             */
/*   Updated: 2020/11/14 17:38:53 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_checkborder(long s)
{
	if (s == 1)
		return (-1);
	else
		return (0);
}

int				ft_atoi(const char *str)
{
	long r;
	long s;

	r = 0;
	s = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
	|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
	{
		s = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		r = r * 10 + (*str - '0');
		if (r == 999999999)
			return (ft_checkborder(s));
		str++;
	}
	return (s * r);
}
