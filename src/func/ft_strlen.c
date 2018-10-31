/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:28:17 by ssandla           #+#    #+#             */
/*   Updated: 2017/11/18 12:28:19 by ssandla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"functions.h"

int		ft_strlen(char *str)
{
	int		len;
	char		*buf;

	if (str == NULL)
		return (0);
	buf = str;
	len = 0;
	while (*buf != '\0')
	{
		len++;
		buf++;
	}
	return (len);
}
