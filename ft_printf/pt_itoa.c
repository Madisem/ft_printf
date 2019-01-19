/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:44:32 by maseidua          #+#    #+#             */
/*   Updated: 2019/01/02 18:05:59 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*pt_itoa(intmax_t	n)
{
	intmax_t	num;
	char		*str;
	int			size;
	intmax_t	na;

	size = 1;
	num = n;
	if (n < 0)
	{
		num = num * (-1);
		size++;
	}
	na = num;
	while (na /= 10)
		size++;
	str = ft_strnew(size);
	if (!str)
		return (NULL);
	str[--size] = num % 10 + '0';
	while (num /= 10)
		str[--size] = (num % 10) + '0';
	if (str[0] == '\0')
		str[0] = '-';
	return (str);
}
