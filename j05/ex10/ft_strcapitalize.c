/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbaril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 23:32:56 by thbaril           #+#    #+#             */
/*   Updated: 2018/02/22 02:29:07 by thbaril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return ;
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 1;
	ft_strlowcase(str);
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') && c == 1)
		{
			c = 0;
			str[i] -= 32;
		}
		i++;
		if ((str[i] < 'a' || str[i] > 'z') && c == 0)
			c = 1;
		if ((str[i] >= '0' && str[i] <= '9') && c == 1)
			c = 0;
	}
	return (str);
}
