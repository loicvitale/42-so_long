/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitale <lvitale@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:42:44 by lvitale           #+#    #+#             */
/*   Updated: 2023/10/30 14:04:14 by lvitale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_pf(unsigned long long pointer, size_t *count)
{
	if (ft_putstr_pf("0x", count) < 0 
		|| ft_putnbrbase_pf(pointer, HEX_LOW_BASE, count) < 0)
		return (-1);
	return (0);
}
