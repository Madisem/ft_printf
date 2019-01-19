/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_defstrcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:46:07 by maseidua          #+#    #+#             */
/*   Updated: 2019/01/17 18:46:15 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_defstrcpy(const char *s1, int num)
{
	char	*tmp;
	size_t	i;

	i = 0;
	while (s1[i] != '.') {
		i++;
	}
	tmp = ft_strnew(i + num);
	if (!tmp)
		return (NULL);
	ft_strncpy(tmp, s1, i + num);
	return (tmp);
}
