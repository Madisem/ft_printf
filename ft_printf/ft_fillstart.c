/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillstart.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 19:21:29 by maseidua          #+#    #+#             */
/*   Updated: 2019/01/02 19:23:54 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"

char	*ft_fillstart(char *dst, char *src)
{
	int i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	return (dst);
}
