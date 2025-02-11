/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:06:04 by mah-ming          #+#    #+#             */
/*   Updated: 2024/11/25 20:55:04 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putcharf(char charactere, int *length);
void	ft_string(char *args, int *length);
void	ft_number(int nbr, int *length);
void	ft_pointer(size_t pointer, int *length);
void	ft_hexadecimal(unsigned int x, int *length, char xX);
void	ft_unsigned_int(unsigned int u, int *length);

int		ft_printf(const char *str, ...);

#endif
