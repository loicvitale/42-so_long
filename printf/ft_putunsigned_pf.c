/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_pf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitale <lvitale@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:57:13 by lvitale           #+#    #+#             */
/*   Updated: 2023/10/30 14:52:55 by lvitale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned_pf(unsigned int n, size_t *count)
{
	if (n / 10)
		if (ft_putnbr_pf(n / 10, count) < 0)
			return (-1);
	if (ft_putchar_pf('0' + n % 10, count) < 0)
		return (-1);
	return (0);
}
