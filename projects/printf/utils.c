/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <joanavar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:04:31 by joanavar          #+#    #+#             */
/*   Updated: 2024/02/08 18:26:40 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int *count)
{
	if (*count == -1)
		return (*count);
	if (write(1, &c, 1) == -1)
	{
		*count = -1;
		return (*count);
	}
	(*count)++;
	return (*count);
}

int	ft_putstr(char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i] && *count != -1)
		ft_putchar(str[i++], count);
	return (*count);
}

int	ft_putnbr_base(long int n, int *count, int base, char flag)
{
	char	*str;

	if ((flag == 'd' || flag == 'i') && (n < INT_MIN || n > INT_MAX))
		return (*count);
	str = "0123456789ABCDEF";
	if (flag != 'X')
		str = "0123456789abcdef";
	if (n < 0 && *count != -1 && (flag == 'd' || flag == 'i'))
	{
		ft_putchar('-', count);
		n = -n;
	}
	if (n < base && *count != -1)
		ft_putchar(str[n % base], count);
	else if (*count != -1)
	{
		ft_putnbr_base(n / base, count, base, flag);
		ft_putchar(str[n % base], count);
	}
	return (*count);
}

int	ft_putnbr_ptr(unsigned long n, int *count, unsigned long base, char flag)
{
	char	*str;

	str = "0123456789abcdef";
	if (n < base && *count != -1)
		ft_putchar(str[n % base], count);
	else if (*count != -1)
	{
		ft_putnbr_base(n / base, count, base, flag);
		ft_putchar(str[n % base], count);
	}
	return (*count);
}

int	dif_letter(char dif, va_list ap, int *count)
{
	if (*count == -1)
		return (*count);
	if (dif == 'c')
		return (ft_putchar(va_arg(ap, int), count));
	else if (dif == 's')
		return (ft_putstr(va_arg(ap, char *), count));
	else if (dif == 'p')
	{
		ft_putstr("0x", count);
		return (ft_putnbr_ptr(va_arg(ap, unsigned long), count, 16, dif));
	}
	else if (dif == 'd' || dif == 'i')
		return (ft_putnbr_base(va_arg(ap, int), count, 10, dif));
	else if (dif == 'u')
		return (ft_putnbr_base(va_arg(ap, unsigned int), count, 10, dif));
	else if (dif == 'x')
		return (ft_putnbr_base(va_arg(ap, unsigned int), count, 16, dif));
	else if (dif == 'X')
		return (ft_putnbr_base(va_arg(ap, unsigned int), count, 16, dif));
	else if (dif == '%')
		return (ft_putchar('%', count));
	return (-1);
}
