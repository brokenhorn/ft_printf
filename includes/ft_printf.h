/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:11:00 by vmaricru          #+#    #+#             */
/*   Updated: 2021/01/22 17:22:14 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_FT_PRINTF_H
# define PRINTF_FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct	s_data
{
	int			flag_zero;
	int			flag_minus;
	int			width;
	int			accuracy;
	int			type;
	va_list		arg;
	int			check;
}				t_data;

int				ft_printf(const char *str, ...);
char			*ft_parse_flag(char *format, t_data **lst);
char			*ft_parse_width(char *format, t_data **lst);
char			*ft_parse_accuracy(char *format, t_data **lst);
char			*ft_parse_type(char *format, t_data **lst);
int				ft_printf_type_c(t_data **lst);
int				ft_printf_type_s(t_data **lst);
int				ft_printf_type_d(t_data **lst);
void			ft_printf_utils_len_put(int len, char **str, t_data **lst);
void			ft_printf_utils_check_m(int check_m);
void			ft_printf_utils_print_space(t_data **lst);
void			ft_printf_utils_print_zero(t_data **lst);
void			ft_printf_type_d_print_i(t_data **lst, int i);
void			ft_printf_type_d_print(char **str, t_data **lst,
		int len, int check_m);
void			ft_printf_type_d_print_accuracy(char **str,
		t_data **lst, int len, int check_m);
void			ft_printf_type_d_print_accuracy0(t_data **lst,
		int i, int check_m);
void			ft_printf_type_d_print_accuracy1(t_data **lst,
		int len, int i, char **str);
int				ft_printf_type_u(t_data **lst);
int				ft_printf_type_p(t_data **lst);
int				ft_check_minus(int check_m, int nmb, t_data **lst);
int				ft_printf_type_x(t_data **lst);
void			ft_lst_re(t_data *lst);
t_data			*ft_lst_dec();
void			ft_printf_type_s_null(t_data **lst, int len);
void			ft_printf_utils_p_acc_else(t_data **lst, char **str, int len);
void			ft_printf_type_p_print_accuracy0(t_data **lst, int i);
void			ft_printf_utils_p_acc_if_m_zero(t_data **lst,
		char **str, int len, int i);

#endif
