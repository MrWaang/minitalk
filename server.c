/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:34:50 by mah-ming          #+#    #+#             */
/*   Updated: 2025/05/19 14:37:38 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	minitalk_usage(int pid)
{
	ft_printf(BLUE"\n\tMINITALK SERVER\n");
	ft_printf(GREEN"\n\tPID: %d\n", pid);
	ft_printf(YELLOW"\tUsage:\n");
	ft_printf(BLUE"\t1. Keep this window open\n");
	ft_printf(RESET"\t2. Use: ./client %d \"message\"\n\n", pid);
}

void	handler(int sig)
{
	static int		bit;
	static char		c;
	static char		buffer[BUFFER_SIZE];
	static size_t	pos;

	if (sig == SIGUSR1)
		c |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		buffer[pos++] = c;
		if (c == '\0' || pos >= BUFFER_SIZE - 1)
		{
			buffer[pos] = '\0';
			write(1, buffer, pos);
			pos = 0;
		}
		bit = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	int	serv_pid;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Usage: ./server\n");
		return (1);
	}
	serv_pid = getpid();
	minitalk_usage(serv_pid);
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
	return (0);
}
