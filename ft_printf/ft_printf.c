/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:34:23 by maseidua          #+#    #+#             */
/*   Updated: 2019/01/03 16:46:38 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"

static int	ft_isflag(char c)
{
	return (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0' || c == '*');
}


char	**ch_pslen(char *fstr, int i, va_list inputs, t_map *modifiers)
{
	int		prn;

	prn = -1;
	if(fstr[i] == '.')
	{
		i++;
		prn = 0;
		if (!(ft_isdigit(fstr[i]) && fstr[i] != '*'))
			modifiers->prcsn = 0;
		while (ft_isdigit(fstr[i]))
			prn = prn * 10 + (fstr[i++] - '0');
		if (fstr[i] == '*')
			modifiers->pstar = '*';
	}
	modifiers->prcsn = prn;
	if (fstr[i] == 'h')
	{
		i++;
		if (fstr[i] == 'h')
			modifiers->length |= F_HASHHH;
		modifiers->length |= F_MINH;
	}
	if (fstr[i] == 'l')
	{
		i++;
		if (fstr[i] == 'l')
			modifiers->length |= F_ZEROLLL;
		modifiers->length |= F_PLUSL;
	}
	if (fstr[i] == 'L')
	{
		i++;
		modifiers->length |= F_SPACELL;
	}
	return (main_funct(fstr, i, inputs, modifiers));
}

char	**ch_fwpl(char *fstr, int i, va_list inputs)
{
	int 	widn;
	t_map	*modifiers;

	modifiers = (t_map *)malloc(sizeof(t_map));
	widn = 0;
	modifiers->flag = 0;
	modifiers->length = 0;
	while (ft_isflag(fstr[++i]))
	{
		if (fstr[i] == '-')
			modifiers->flag |= F_MINH;
		if (fstr[i] == '+')
			modifiers->flag |= F_PLUSL;
		if (fstr[i] == ' ')
			modifiers->flag |= F_SPACELL;
		if (fstr[i] == '#')
			modifiers->flag |= F_HASHHH;
		if (fstr[i] == '0')
			modifiers->flag |= F_ZEROLLL;
		if (fstr[i] == '*')
			modifiers->wstar = '*';
	}
	while (ft_isdigit(fstr[i]))
		widn = widn * 10 + (fstr[i++] - '0');
	modifiers->width = widn;
	return (ch_pslen(fstr, i, inputs, modifiers));
}

char	*reading(char *fstr, va_list inputs, int i)
{
	int		j;
	char	**pt_arr;
	char	*printa;
	char	*temp;

	j = 0;
	printa = ft_strnew(ft_strlen(fstr));
	while (fstr[i])
	{
		while(fstr[i] != '%' && fstr[i])
			printa[j++] = fstr[i++];
		if (fstr[i] == '%')
		{
			pt_arr = ch_fwpl(fstr, i, inputs);
			temp = ft_strjoin(printa, pt_arr[0]);
			free(printa);
			printa = ft_strnew(ft_strlen(fstr) + ft_strlen(pt_arr[0]));
			printa = ft_strcpy(printa, temp);
			free(temp);
			i = ft_atoi(pt_arr[1]);
			j = ft_strlen(printa);
			i++;
			free(pt_arr);
		}
	}
	return (printa);
}

int	ft_printf(char *fstr, ...)
{
	char	*printa;
	va_list inputs;

	va_start(inputs, fstr);
	printa = reading(fstr, inputs, 0);
	ft_putstr(printa);
	va_end(inputs);
	return (ft_strlen(printa));
}
