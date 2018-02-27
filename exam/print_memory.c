/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbaril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 19:38:41 by thbaril           #+#    #+#             */
/*   Updated: 2018/02/27 20:43:35 by thbaril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

void	ft_print_hex(unsigned char *addr, size_t size)
{
	int		i;
	int		c;
	char	*b;

	i = 0;
	b = "0123456789abcdef";
	c = 0;
	while (i < 16 && i < size)
	{
		if (i % 2 == 0 && i != 0)
		{
			ft_putchar(' ');
			c++;
		}
		ft_putchar(b[addr[i] % 16]);
		c++;
		ft_putchar(b[addr[i] / 16]);
		c++;
		i++;
	}
	while (++c < 41)
		ft_putchar(' ');
	return ;
}

void	print_memory(const void *addr, size_t size)
{
	int				i;
	int				mod;
	unsigned char	*tmp;

	i = 0;
	mod = 0;
	tmp = (unsigned char *)addr;
	ft_print_hex(tmp, size);
	while (i < 16 && i < size)
	{
		if (tmp[i] < 32 || tmp[i] > 127)
			ft_putchar('.');
		else
			ft_putchar(tmp[i]);
		i++;
	}
	ft_putchar('\n');
	if (size > 16)
		print_memory(tmp + 16, size - 16);
	return ;
}
