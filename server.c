/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 05:58:16 by mah-ming          #+#    #+#             */
/*   Updated: 2025/05/24 07:45:49 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_server	g_server = {0, 0, 0};

static void	handle_signal(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		g_server.c |= (0 << g_server.bit);
	else if (sig == SIGUSR2)
		g_server.c |= (1 << g_server.bit);
	g_server.bit++;
	if (g_server.bit == 8)
	{
		if (g_server.c == '\0')
		{
			write(1, "\n", 1);
			g_server.pid = 0;
		}
		else
			write(1, &g_server.c, 1);
		g_server.bit = 0;
		g_server.c = 0;
	}
	if (g_server.pid == 0)
		g_server.pid = info->si_pid;
	kill(info->si_pid, SIGUSR1);
}

static void	setup_signals(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

static void	print_pid(void)
{
	ft_printf("Server PID: %d\n", getpid());
	ft_printf("Waiting for messages...\n");
}

int	main(void)
{
	setup_signals();
	print_pid();
	while (1)
		pause();
	return (0);
}
