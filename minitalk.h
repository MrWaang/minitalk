/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:22:58 by mah-ming          #+#    #+#             */
/*   Updated: 2025/05/24 00:36:54 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define RED     "\033[0;31m"
# define GREEN   "\033[0;32m"
# define YELLOW  "\033[0;33m"
# define BLUE    "\033[0;34m"
# define RESET   "\033[0m"

typedef struct s_msg
{
	int		phase;
	size_t	size;
	size_t	size_bit;
	char	*buffer;
	size_t	pos;
	int		bit;
	char	current_char;
}				t_msg;

// PRINTF
void	ft_putcharf(char charactere, int *length);
void	ft_string(char *args, int *length);
void	ft_number(int nbr, int *length);
void	ft_pointer(size_t pointer, int *length);
void	ft_hexadecimal(unsigned int x, int *length, char xX);
void	ft_unsigned_int(unsigned int u, int *length);
int		ft_printf(const char *str, ...);

// UTILS
int		ft_atoi(const char *str);
void	send_bit(int pid, int bit);
void	reset_message(t_msg *msg);

#endif
