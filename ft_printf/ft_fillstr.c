/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 15:32:11 by maseidua          #+#    #+#             */
/*   Updated: 2019/01/02 00:42:28 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_fillstr(char *dst, char *src, int i)
{
	int j;
	int len;

	j = 0;
	len = ft_strlen(dst);
	while (src[j] && i < len)
		dst[i++] = src[j++];
	return (dst);
}
