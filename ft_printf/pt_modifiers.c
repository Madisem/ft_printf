/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_modifiers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 12:20:58 by maseidua          #+#    #+#             */
/*   Updated: 2019/01/03 19:56:50 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"

char	*fpt_c(va_list inputs, t_map *modifiers)
{
	char	*warr;
	char 	c;

	warr = apply_width(inputs, modifiers);
	c = (char)va_arg(inputs, int);
	if ((modifiers->flag & F_MINH) == 1)
	   warr[0] = c;
	if ((modifiers->flag & F_MINH) != 1)
		warr[ft_strlen(warr)] = c;
	return (warr);
}

char	*fpt_s(va_list inputs, t_map *modifiers)
{
	char	*warr;
	char	*s;
	int 	ps;

	s = va_arg(inputs, char*);
	if (modifiers->prcsn == 0)
		s = "";
	if (modifiers->prcsn > 0)
		s = ft_strsub(s, 0, modifiers->prcsn);
	if (modifiers->pstar == '*')
	{
		ps = va_arg(inputs, int);
		s = ft_strsub(s, 0, ps);
	}
	if ((int)ft_strlen(s) < modifiers->width)
	{
		warr = apply_width(inputs, modifiers);
		if ((modifiers->flag & F_MINH) != 1)
			ft_fillstr(warr, s, modifiers->width - ft_strlen(s));
		else
			ft_fillstart(warr, s);
		return (warr);
	}
	return (s);
}

int		length_di(va_list inputs, t_map *modifiers)
{
	intmax_t  n;

	if ((modifiers->length & F_MINH) == 1)
		n = (short int)va_arg(inputs, int);
	else if ((modifiers->length & F_PLUSL) == 8)
		n = va_arg(inputs, long int);
	else if ((modifiers->length & F_SPACELL) == 16)
		n = va_arg(inputs, long long int);
	else if ((modifiers->length & F_HASHHH) == 32)
		n = (signed char)va_arg(inputs, int);
	else
		n = va_arg(inputs, int);
	return (n);
}

char	*fpt_di(va_list inputs, t_map *modifiers)
{
	intmax_t	n;
	char		*num;
	char		*parr;

	n = length_di(inputs, modifiers);
	num = pt_itoa(n);
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

char	*fpt_di_flags(t_map *modifiers, va_list inputs,  char *parr, intmax_t n)
{
	char	*warr;
	char	*num;

	num = pt_itoa(n);
	warr = apply_width(inputs, modifiers);
	if ((modifiers->flag & F_MINH) == 1)
		ft_fillstart(warr, parr);
	else
	{
		ft_fillstr(warr, parr, modifiers->width - ft_strlen(num));
		if (n < 0 && ((modifiers->flag & F_ZEROLLL) == 64))
		{
			warr[0] = '-';
			warr[modifiers->width - ft_strlen(num)] = '0';
		}
	}
	if (((modifiers->flag & F_PLUSL) == 8) && n >= 0)
	{
		 if ((modifiers->flag & F_ZEROLLL) == 64)
			 warr[0] = '+';
	 	else
	 		warr[modifiers->width - ft_strlen(num) - 1] = '+';
	}
	return (warr);
}

char	**main_funct(char *fstr, int i, va_list inputs, t_map *modifiers)
{
	char	**pt_arr;

	pt_arr = (char**)malloc(sizeof(char*) * 2);
	if (fstr[i] == 'c')
		pt_arr[0] = fpt_c(inputs, modifiers);
	if (fstr[i] == 's')
		pt_arr[0] = fpt_s(inputs, modifiers);
	if (fstr[i] == 'd' || fstr[i] == 'i')
		pt_arr[0] = fpt_di(inputs, modifiers);
	if (fstr[i] == 'f')
		pt_arr[0] = fpt_f(inputs, modifiers);
	pt_arr[1] = ft_itoa(i);
	return (pt_arr);
}
