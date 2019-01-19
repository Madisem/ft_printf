/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 18:25:16 by maseidua          #+#    #+#             */
/*   Updated: 2019/01/06 18:25:59 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
//# include "libft/libft.h"

char *ft_itoa_base(intmax_t value, int base)
{
  char      *b_arr;
  char      *bases;
  int       i;
  intmax_t	num;
  intmax_t  na;

  i = 0;
  num = value;
  if (value < 0)
  {
    num = num * (-1);
    i++;
  }
  na = num;
  bases = "0123456789ABCDEF";
  while ((na /= base) > 0)
   i++;
  b_arr = ft_strnew(++i);
  if (!b_arr)
		return (NULL);
	b_arr[--i] = num % base + '0';
	while ((num /= base) > 0)
		b_arr[--i] = bases[num % base];
	if (b_arr[0] == '\0')
		b_arr[0] = '-';
	return (b_arr);
}
