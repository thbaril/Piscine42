/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbaril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 01:12:43 by thbaril           #+#    #+#             */
/*   Updated: 2018/02/21 00:33:00 by thbaril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int	j;
	int	tmp;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		tmp = i;
		while (str[i] == to_find[j])
		{
			i++;
			j++;
		}
		if (to_find[j] == '\0')
			return (str + tmp);
		i = tmp;
		i++;
	}
	return (NULL);
}
