/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:28:40 by ssandla           #+#    #+#             */
/*   Updated: 2017/11/18 12:28:41 by ssandla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"functions.h"

char		*merge_strings(char *str, char *plus, int n)
{
	char		*result;
	int		total_len;

	total_len = ft_strlen(str) + ft_strlen(plus) + 1;
	result = (char*)malloc(sizeof(char) * total_len);
	if (result != NULL)
	{
		if (str != NULL)
		{
			ft_strcpy(result, str);
			ft_strncat(result, plus, n);
			free(str);
		}
		else
			ft_strncpy(result, plus, n);
		return (result);
	}
	return (str);
}
