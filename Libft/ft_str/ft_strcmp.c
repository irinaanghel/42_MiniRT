/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:22:59 by aanghel           #+#    #+#             */
/*   Updated: 2023/01/07 01:09:18 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Comparete two string
 * 
 * @param s1 string one
 * @param s2 string two
 * 
 * @return int 1 if the string is equal,
 * 0 if the string isn't equal
 */
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[i] == s2[i])
	{
		i++;
		if (!s1[i] && !s2[i])
			return (1);
	}
	return (0);
}
