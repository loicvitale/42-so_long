/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitale <lvitale@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:04:44 by lvitale           #+#    #+#             */
/*   Updated: 2023/10/30 14:48:43 by lvitale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_pf(int n, size_t *count)
{
	if (n == -2147483648)
	{
		if (ft_putnbr_pf((n / 10), count) < 0)
			return (-1);
		if (ft_putchar_pf('8', count) < 0)
			return (-1);
	}
	else
	{
		if (n < 0)
		{
			if (ft_putchar_pf ('-', count) < 0)
				return (-1);
			n *= -1;
		}
		if (n / 10)
			if (ft_putnbr_pf(n / 10, count) < 0)
				return (-1);
		if (ft_putchar_pf('0' + n % 10, count) < 0)
			return (-1);
	}
	return (0);
}
