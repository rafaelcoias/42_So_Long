/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:06:00 by rade-sar          #+#    #+#             */
/*   Updated: 2021/10/28 18:31:39 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	lt;

	lt = c;
	while (*s != '\0')
	{
		if (*s == lt)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && lt == '\0')
		return ((char *)s);
	return (NULL);
}
