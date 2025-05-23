/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:34:50 by mah-ming          #+#    #+#             */
/*   Updated: 2025/05/24 01:33:01 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_msg	g_msg;

static void	minitalk_usage(int pid)
{
	ft_printf(BLUE"\n\tMINITALK SERVER\n");
	ft_printf(GREEN"\n\tPID: %d\n", pid);
	ft_printf(YELLOW"\tUsage:\n");
	ft_printf(BLUE"\t1. Keep this window open\n");
	ft_printf(RESET"\t2. Use: ./client %d \"message\"\n\n", pid);
}

static void	process_size_bit(int sig)
{
	if (sig == SIGUSR1)
		g_msg.size |= (1UL << g_msg.size_bit);
	g_msg.size_bit++;
	if (g_msg.size_bit == sizeof(size_t) * 8)
	{
		g_msg.buffer = malloc(g_msg.size + 1);
		if (!g_msg.buffer)
		{
			reset_message(&g_msg);
			return ;
		}
		g_msg.phase = 1;
	}
}

static void	process_message_bit(void)
{
	g_msg.buffer[g_msg.pos] = g_msg.current_char;
	g_msg.pos++;
	if (g_msg.current_char == '\0' || g_msg.pos >= g_msg.size)
	{
		g_msg.buffer[g_msg.pos] = '\0';
		write(1, g_msg.buffer, g_msg.pos - 1);
		write(1, "\n", 1);
		reset_message(&g_msg);
	}
	g_msg.bit = 0;
	g_msg.current_char = 0;
}

void	handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (g_msg.phase == 0)
		process_size_bit(sig);
	else
	{
		if (sig == SIGUSR1)
			g_msg.current_char |= (0x01 << g_msg.bit);
		g_msg.bit++;
		if (g_msg.bit == 8)
			process_message_bit();
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					serv_pid;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Usage: ./server\n");
		return (1);
	}
	serv_pid = getpid();
	minitalk_usage(serv_pid);
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
