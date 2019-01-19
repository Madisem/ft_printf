/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:44:32 by maseidua          #+#    #+#             */
/*   Updated: 2019/01/17 15:54:55 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_ftoa(long double num)
{
	//intmax_t	num;
	char		*str;
	int			a;
	long double na;

	na = num;
	a = (int)na;
	str = ft_itoa(a);
	str[ft_strlen(str)] = '.';
	if (a < 0)
		na = na * (-1);
	na = na - (int)na;
 	while ((na *= 10) > 0)
 	{
	 	str = ft_strjoin(str, ft_itoa((int)na));
	 	na = na - (int)na;
 	}
	return (str);
}
