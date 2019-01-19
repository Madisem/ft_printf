/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 23:18:32 by maseidua          #+#    #+#             */
/*   Updated: 2019/01/17 19:41:10 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int main()
{

	printf("floats %#012.3f\n", -56.907);
	ft_printf("floats %#012.3f\n", -56.907);
	printf("what else we can check f %f\n", -962323327323228.465454543347839322353496059653025344542);
	ft_printf("what else we can check f %f\n", -9622332323378.4345344356666666326665396059653022);	

	 ft_printf("This time it %.s perfectly!\n", "sentence write");
 	ft_printf("Hello Madina %.4d this time\n", -78556);
	ft_printf("Hello Madina %.0d this time\n", 0);
	ft_printf("Hello Madina %.2d this time\n", 410000);
	ft_printf("Hello Madina %- 10.4d this time\n", -7);
	ft_printf("Hello Madina %+5d this time\n", 78);
	ft_printf("Characters: %c %c \n", 'a', 65);
	ft_printf ("Decimals: %d %ld\n", 1977, 650000L);
	ft_printf ("Preceding with blanks: %10d \n", 1977);
	ft_printf ("Preceding with zeros: %010d \n", 1977); 
	printf ("Characters: %c %c \n", 'a', 65);
  printf ("Decimals: %d %ld\n", 1977, 650000L);
  printf ("Preceding with blanks: %10d \n", 1977);
  printf ("Preceding with zeros: %010d \n", 1977);
	printf("This time it %.s perfectly!\n", "must work");
	printf("Hello Madina %.4d this time\n", -78556);
	printf("Hello Madina %.0d this time\n", 0);
	printf("Hello Madina %.2d this time\n", 410000);
	printf("Hello Madina %- 10.4d this time\n", -7);
	printf("Hello Madina %+5d this time\n", 78);
//	ft_printf("%d\n", ret);
//	ft_printf("%d\n", ret);
//	ft_printf("%d\n", ret);
//	ft_printf("%d\n", ret); 
	return (0);
}
