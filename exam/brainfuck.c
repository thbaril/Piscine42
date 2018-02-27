/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbaril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 18:14:06 by thbaril           #+#    #+#             */
/*   Updated: 2018/02/27 19:30:10 by thbaril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_empty(void)
{
	char	*ret;
	int		i;

	if (!(ret = (char *)malloc(sizeof(char) * 2048)))
		return (NULL);
	i = 0;
	while (i < 2048)
	{
		ret[i] = '\0';
		i++;
	}
	return (ret);
}

void	ft_brainfuck(char *str)
{
	int		i;
	int		last;
	char	*ptr;

	ptr = ft_empty();
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '[')
			last = i;
		if (str[i] == ']' && *ptr != 0)
			i = last;
		if (str[i] == '+')
			*ptr += 1;
		if (str[i] == '-')
			*ptr -= 1;
		if (str[i] == '>')
			ptr++;
		if (str[i] == '<')
			ptr--;
		if (str[i] == '.')
			ft_putchar(*ptr);
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2 && argv[1][0])
		ft_brainfuck(argv[1]);
	else
		write(1, "\n", 1);
}
