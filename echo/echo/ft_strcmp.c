/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 13:38:49 by ssandla           #+#    #+#             */
/*   Updated: 2017/09/02 13:38:51 by ssandla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "echo.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				index;
	unsigned char	*s1c;
	unsigned char	*s2c;

	index = 0;
	s1c = (unsigned char *)s1;
	s2c = (unsigned char *)s2;
	while (s1c[index] && s2c[index] && s1c[index] == s2c[index])
		index++;
	return (s1c[index] - s2c[index]);
}
