/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbaril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 21:58:40 by thbaril           #+#    #+#             */
/*   Updated: 2018/02/28 03:29:01 by thbaril          ###   ########.fr       */
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
	int	n;

	i = 0;
	r = 0;
	n = 1;
	if (str[0] == '-')
	{
		n = -1;
		i++;
	}
	while (str[i])
	{
		if (n < 0)
			r = (r * base) - ft_value(str[i]);
		else
			r = (r * base) + ft_value(str[i]);
		i++;
	}
	return (r);
}
