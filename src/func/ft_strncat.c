/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:29:46 by ssandla           #+#    #+#             */
/*   Updated: 2017/11/18 12:29:48 by ssandla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"functions.h"

char		*ft_strncat(char *dest, char *src, int nb)
{
	int		i;
	int		dest_len;

	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0' && i < nb)
	{
		dest[dest_len + i] = src[i];
		++i;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}
