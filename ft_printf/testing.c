/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:22:01 by maseidua          #+#    #+#             */
/*   Updated: 2019/01/17 18:11:04 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char *ft_ftoa(long double num);

int main()
{
	char	*hexan;

	hexan = ft_ftoa(-36.09);
	ft_putendl(hexan);
	return (0);
}
