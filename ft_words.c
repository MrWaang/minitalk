/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:38:49 by mah-ming          #+#    #+#             */
/*   Updated: 2024/11/25 20:55:02 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_number(int nbr, int *length)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*length) += 11;
		return ;
	}
	if (nbr < 0)
	{
		ft_putcharf('-', length);
		ft_number(nbr * -1, length);
	}
	if (nbr >= 10)
		ft_number(nbr / 10, length);
	ft_putcharf(nbr % 10 + '0', length);
}

void	ft_pointer(size_t pointer, int *length)
{
	char	string[25];
	int		i;
	char	*base;

	base = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	(*length) += 2;
	if (pointer == 0)
	{
		ft_putcharf('0', length);
		return ;
	}
	while (pointer != 0)
	{
		string[i] = base[pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	while (i--)
		ft_putcharf(string[i], length);
}

void	ft_hexadecimal(unsigned int x, int *length, char xX)
{
	char	string[25];
	int		i;
	char	*base;

	i = 0;
	if (xX == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (x == 0)
	{
		ft_putcharf('0', length);
		return ;
	}
	while (x != 0)
	{
		string[i] = base[x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		ft_putcharf(string[i], length);
}

void	ft_unsigned_int(unsigned int u, int *length)
{
	if (u >= 10)
		ft_unsigned_int(u / 10, length);
	ft_putcharf(u % 10 + '0', length);
}
