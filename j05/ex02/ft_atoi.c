/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbaril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:55:50 by thbaril           #+#    #+#             */
/*   Updated: 2018/02/17 13:34:12 by thbaril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_purge_start(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	return (i);
}

int		ft_atoi(char *str)
{
	int	i;
	int r;
	int	n;

	i = ft_purge_start(str);
	n = 1;
	if (str[i] == '-')
		n = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	r = 0;
	while ((str[i] <= '9' && str[i] >= '0') && str[i] != '\0')
	{
		if (n > 0)
			r = r * 10 + (str[i] - '0');
		else
			r = r * 10 - (str[i] - '0');
		i++;
	}
	return (r);
}
