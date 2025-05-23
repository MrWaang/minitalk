/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:21:58 by mah-ming          #+#    #+#             */
/*   Updated: 2025/05/23 17:47:22 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		send_bit(pid, (c & (0x01 << bit)) != 0);
		bit++;
	}
}

void	send_size(int pid, size_t size)
{
	int	bit;

	bit = 0;
	while (bit < (int)(sizeof(size_t) * 8))
	{
		send_bit(pid, (size & (1UL << bit)) != 0);
		bit++;
	}
}

void	send_string(int pid, char *str)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (str[len])
		len++;
	len++;
	send_size(pid, len);
	i = 0;
	while (i < len)
	{
		send_char(pid, str[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", av[0]);
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_printf("Invalid PID\n");
		return (1);
	}
	send_string(pid, av[2]);
	return (0);
}
