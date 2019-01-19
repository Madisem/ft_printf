/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:19:56 by maseidua          #+#    #+#             */
/*   Updated: 2019/01/17 18:20:08 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		length_f(va_list inputs, t_map *modifiers)
{
	double  n;

	if ((modifiers->length & F_ZEROLLL) == 1)
		n = (long double)va_arg(inputs, double);
	else
		n = va_arg(inputs, double);
	return (n);
}

char	*fpt_f(va_list inputs, t_map *modifiers)
{
	double	n;
	int 		a;
	char		*num;
	char		*parr;

	n = length_f(inputs, modifiers);
	num = ft_ftoa((long double)n);
	if (modifiers->prcsn == 0 && n == 0)
		parr = ft_strchrcpy(num, '.');
	if (modifiers->prcsn == -1)
		parr = ft_defstrcpy(num, 6);
	if (modifiers->pstar == '*')
	{
		a = va_arg(inputs, int);
		parr = ft_defstrcpy(num, a);
	}
	else
		parr = ft_defstrcpy(num, modifiers->prcsn);
	if ((int)ft_strlen(parr) < modifiers->width)
		return (fpt_f_flags(modifiers, inputs, parr, (int)n));
	if (((modifiers->width & F_PLUSL) == 8) && (int)n >= 0)
		parr = ft_addchr(parr, '+');
	free(num);
	return (parr);
}

char	*fpt_f_flags(t_map *modifiers, va_list inputs, char *parr, int n)
{
	char	*warr;
	char	*num;

	warr = apply_width(inputs, modifiers);
	if ((modifiers->flag & F_MINH) == 1)
		ft_fillstart(warr, parr);
	else
	{
		ft_fillstr(warr, parr, modifiers->width - ft_strlen(parr));
		if (n < 0 && ((modifiers->flag & F_ZEROLLL) == 64))
		{
			warr[0] = '-';
			warr[modifiers->width - ft_strlen(parr)] = '0';
		}
	}
	if (((modifiers->flag & F_PLUSL) == 8) && n >= 0)
	{
		if ((modifiers->flag & F_ZEROLLL) == 64)
			warr[0] = '+';
	 	else
	 		warr[modifiers->width - ft_strlen(parr) - 1] = '+';
	}
	return (warr);
}
