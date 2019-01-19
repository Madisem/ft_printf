/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_ouxX.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:19:55 by maseidua          #+#    #+#             */
/*   Updated: 2019/01/05 18:20:17 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		length_uoxX(va_list inputs, t_map *modifiers)
{
	intmax_t  n;

	if ((modifiers->length & F_MINH) == 1)
		n = (unsigned short int)va_arg(inputs, int);
	else if ((modifiers->length & F_PLUSL) == 8)
		n = va_arg(inputs, unsigned long int);
	else if ((modifiers->length & F_SPACELL) == 16)
		n = va_arg(inputs, unsigned long long int);
	else if ((modifiers->length & F_HASHHH) == 32)
		n = (unsigned char)va_arg(inputs, int);
	else
		n = va_arg(inputs, unsigned int);
	return (n);
}

char	*fpt_oxX(va_list inputs, t_map *modifiers, char c)
{
	intmax_t	n;
	char		*num;
	char		*parr;

	n = length_uoxX(inputs, modifiers);
	if (c == 'o')

	if (modifiers->prcsn == 0 && n == 0)
		num = "";
	if ((int)ft_strlen(num) < modifiers->prcsn)
	{
		parr = apply_prcsn(inputs, modifiers, n);
		ft_fillstr(parr, num, ft_strlen(parr) - ft_strlen(num));
		if (n < 0)
		{
			parr[ft_strlen(parr) - ft_strlen(num)] = '0';
			parr[0] = '-';
		}
	}
	if ((int)ft_strlen(num) >= modifiers->prcsn)
		parr = num;
	if ((int)ft_strlen(parr) < modifiers->width)
		return (fpt_di_flags(modifiers, inputs, parr, n));
	if (((modifiers->width & F_PLUSL) == 8) && n >= 0)
		parr = ft_addchr(num, '+');
	return (parr);
}
