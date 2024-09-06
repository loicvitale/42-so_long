/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitale <lvitale@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:23:18 by lvitale           #+#    #+#             */
/*   Updated: 2023/10/30 14:53:31 by lvitale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert(char c, va_list lst_arg, size_t *count)
{
	if (c == 'c')
		return (ft_putchar_pf(va_arg(lst_arg, int), count));
	else if (c == 's')
		return (ft_putstr_pf(va_arg(lst_arg, char *), count));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_pf(va_arg(lst_arg, int), count));
	else if (c == 'x')
		return (ft_putnbrbase_pf(va_arg(lst_arg, unsigned int), \
		HEX_LOW_BASE, count));
	else if (c == 'X')
		return (ft_putnbrbase_pf(va_arg(lst_arg, unsigned int), \
		HEX_UPP_BASE, count));
	else if (c == 'u')
		return (ft_putunsigned_pf(va_arg(lst_arg, int), count));
	else if (c == 'p')
		return (ft_putptr_pf(va_arg(lst_arg, unsigned long long), count));
	else if (c == '%')
		return (ft_putchar_pf(c, count));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	lst_arg;
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	va_start(lst_arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (ft_convert(format[++i], lst_arg, &count) < 0)
				return (-1);
		}
		else
			if (ft_putchar_pf(format[i], &count) < 0)
				return (-1);
		i++;
	}
	va_end(lst_arg); 
	return (count);
}
