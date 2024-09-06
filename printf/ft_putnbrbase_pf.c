/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase_pf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitale <lvitale@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:20:57 by lvitale           #+#    #+#             */
/*   Updated: 2023/10/30 14:51:39 by lvitale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_putnbrbase_pf(unsigned long long n, char *base, size_t *count)
{
	long long	nb;
	size_t		size_base;

	nb = n;
	size_base = ft_strlen(base);
	if (nb / size_base)
		if (ft_putnbrbase_pf(nb / size_base, base, count) < 0)
			return (-1);
	if (ft_putchar_pf(base[nb % size_base], count) < 0)
		return (-1);
	return (0);
}
