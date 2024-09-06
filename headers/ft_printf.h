/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitale <lvitale@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:25:20 by lvitale           #+#    #+#             */
/*   Updated: 2023/10/31 09:20:17 by lvitale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define HEX_UPP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"

int	ft_printf(const char *format, ...);
int	ft_putchar_pf(char c, size_t *count);
int	ft_putstr_pf(char *str, size_t *count);
int	ft_putnbr_pf(int n, size_t *count);
int	ft_putunsigned_pf(unsigned int n, size_t *count);
int	ft_putnbrbase_pf(unsigned long long n, char *base, size_t *count);
int	ft_putptr_pf(unsigned long long pointer, size_t *count);

#endif
