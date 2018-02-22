/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbaril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 21:42:47 by thbaril           #+#    #+#             */
/*   Updated: 2018/02/18 22:58:35 by thbaril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_count_w(char *str)
{
	int	i;
	int	c;
	int	add;

	add = 0;
	i = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] != '\n' && str[i] != '\t' && str[i] != ' ' && add == 0)
		{
			add = 1;
			c++;
		}
		if (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
			add = 0;
		i++;
	}
	return (c);
}

int		ft_size_w(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\t' && str[i] != ' ' && str[i])
		i++;
	return (i);
}

int		ft_go_next(char *str)
{
	int	i;

	i = 0;
	while ((str[i] == '\n' || str[i] == '\t' || str[i] == ' ') && str[i])
		i++;
	return (i);
}

void	ft_strcpy(char *ret, char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return ;
}

char	**ft_split_whitespaces(char *str)
{
	int		i;
	int		tmp;
	int		w;
	char	**ret;

	if (!(ret = (char **)malloc(sizeof(char *) * ft_count_w(str) + 1)))
		return (NULL);
	w = 0;
	i = 0;
	while (str[i])
	{
		i += ft_go_next(str + i);
		tmp = ft_size_w(str + i);
		if (str[i])
		{
			if (!(ret[w] = (char *)malloc(sizeof(char) * tmp + 1)))
				return (NULL);
			ft_strcpy(ret[w++], str + i, tmp);
		}
		i += tmp;
	}
	if (!(ret[w] = (char *)malloc(sizeof(char))))
		return (NULL);
	ret[w] = NULL;
	return (ret);
}
