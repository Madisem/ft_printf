/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:36:43 by maseidua          #+#    #+#             */
/*   Updated: 2019/01/02 19:27:38 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <locale.h>
# define F_MINH		1
# define F_PLUSL	8				//l
# define F_SPACELL	16   //ll
# define F_HASHHH	32
# define F_ZEROLLL	64			//L

typedef	struct	s_map
{
	char			flag;
	char			wstar;
	int				width;
	char			pstar;
	int				prcsn;
	char			length;
}					t_map;

char	*pt_itoa(intmax_t	n);
char	*ft_defstrcpy(const char *s1, int num);
char	*ft_ftoa(long double num);
char	*ft_addchr(char	*src, char c);
char	*ft_fillstart(char *dst, char *src);
char	*ft_fillstr(char *dst, char *src, int i);
char	*fill_prscn_arr(int num, intmax_t n);
char	*ft_itoa_base(intmax_t value, int base);
char	*apply_prcsn(va_list inputs, t_map *modifiers, intmax_t n);
char	*apply_width(va_list inputs, t_map *modifiers);
int		length_f(va_list inputs, t_map *modifiers);
char	*fpt_f(va_list inputs, t_map *modifiers);
char	*fpt_f_flags(t_map *modifiers, va_list inputs, char *parr, int n);
char	*fpt_c(va_list inputs, t_map *modifiers);
char	*fpt_s(va_list inputs, t_map *modifiers);
char	*fpt_di_flags(t_map *modifiers, va_list inputs, char *parr, intmax_t n);
int		length_di(va_list inputs, t_map *modifiers);
char	*fpt_di(va_list inputs, t_map *modifiers);
char	**main_funct(char *fstr, int i, va_list inputs, t_map *modifiers);
char	**ch_pslen(char *fstr, int i, va_list inputs, t_map *modifiers);
char	**ch_fwpl(char *fstr, int i, va_list inputs);
char	*reading(char *fstr, va_list inputs, int i);
int		ft_printf(char *fstr, ...);

#endif
