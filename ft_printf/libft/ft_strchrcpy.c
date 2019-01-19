/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:37:09 by maseidua          #+#    #+#             */
/*   Updated: 2019/01/17 18:37:15 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrcpy(const char *s1, char c)
{
	char	*tmp;
	size_t	i;

	i = 0;
	while (s1[i] != c) {
		i++;
	}
	tmp = ft_strnew(i);
	if (!tmp)
		return (NULL);
	ft_strncpy(tmp, s1, i);
	return (tmp);
}
