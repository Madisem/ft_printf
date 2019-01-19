/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:41:51 by maseidua          #+#    #+#             */
/*   Updated: 2018/12/29 16:15:05 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
int main()
{
	int number;
	char	j;
	long int	i;
	number = 81;
	j = '9';
	i = 86905505505666665;

	wchar_t *s;
    s = (wchar_t *) malloc(sizeof(wchar_t) * 2);
    s[0] = 0xC389;
    s[1] = 0;

    setlocale(LC_ALL, "");
	printf("%ls\n", s);

	wchar_t x[] = L"madinasdasdççççsjkdfgasdjb";
	printf("Hello it is minus %ls madina\n", x);
	printf("Hello it is minus %7.4d madina\n", -78);
	printf("%.f\n", 4.7865);
 	printf("%hhd and  %ld are the numbers to be printed \n", j, i);
	printf ("Some different radixes: %d %x %o %X %x %#o \n", 100, 100, 100, 100, 100, 100);
    printf ("floats: %4.4f %+.0e %E \n", 3.1416826, 3.1416, 3.1416);
	printf ("Width trick: %*d \n", 5, 10);
	printf("%10d is the number to be printed\n", number);
    printf("%x is also the number I guess \n", 156);  
    printf("%X I have no ideo what it will print\n", 8965);
	return (0);
}
