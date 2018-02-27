/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbaril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 21:58:40 by thbaril           #+#    #+#             */
/*   Updated: 2018/02/27 22:22:52 by thbaril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}

int	ft_atoi_base(const char *str, int base)
{
	int	r;
	int	i;

	i = 0;
	r = 0;
	while (str[i])
	{
		r *= base;
		r += ft_value(str[i]);
		i++;
	}
	return (r);
}
