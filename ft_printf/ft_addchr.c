/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 16:44:41 by maseidua          #+#    #+#             */
/*   Updated: 2019/01/02 19:19:40 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"

char	*ft_addchr(char	*src, char c)
{
	char	*dst;

	dst = ft_strnew(ft_strlen(src) + 1);
	dst[0] = c;
	ft_fillstr(dst, src, 1);
	return (dst);
}
