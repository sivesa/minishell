/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:29:00 by ssandla           #+#    #+#             */
/*   Updated: 2017/11/18 12:29:02 by ssandla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"functions.h"

char		*ft_strcat(char *dest, char *src)
{
	int		i;
	int		dest_len;

	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		++i;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}
