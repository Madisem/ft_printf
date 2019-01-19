/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 21:35:17 by maseidua          #+#    #+#             */
/*   Updated: 2019/01/03 18:53:19 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*apply_width(va_list inputs, t_map *modifiers)
{
	char *ansa;
	int a;

	ansa = ft_strnew(modifiers->width);
	if (modifiers->wstar == '*')
	{
		a = (int)va_arg(inputs, char*);
		ansa = ft_strnew(a);
	}
	if (((modifiers->flag & F_ZEROLLL) != 64) ||
	(((modifiers->flag & F_ZEROLLL) == 64) && (modifiers->flag & F_MINH) == 1))
		ft_memset(ansa, ' ', modifiers->width);
	if (((modifiers->flag & F_ZEROLLL) == 64) && (modifiers->flag & F_MINH) != 1)
		ft_memset(ansa, '0', modifiers->width);
	return (ansa);
}

char	*fill_prscn_arr(int num, intmax_t n)
{
	char *prcsn_arr;

	if (n < 0)
	{
		prcsn_arr = ft_strnew(num + 1);
		ft_memset(prcsn_arr, '0', num + 1);
	}
	else
	{
		prcsn_arr = ft_strnew(num);
		ft_memset(prcsn_arr, '0', num);
	}
	return (prcsn_arr);
}

char	*apply_prcsn(va_list inputs, t_map *modifiers, intmax_t n)
{
	char *ansa;
	int a;

	ansa = fill_prscn_arr(modifiers->prcsn, n);
	if (modifiers->pstar == '*')
	{
		a = va_arg(inputs, int);
		ansa = fill_prscn_arr(a, n);
		return (ansa);
	}
	return (ansa);
}
