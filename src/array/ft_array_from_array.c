/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_from_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:25:45 by ssandla           #+#    #+#             */
/*   Updated: 2017/11/24 13:12:42 by ssandla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"functions.h"
#include	"arrays.h"

char		**ft_array_from_array(char **arr)
{
	char		**new_array;
	int		len;
	int		str_len;
	int		i;

	len = ft_array_length(arr);
	new_array = (char**)malloc(sizeof(char*) * (len + 1));
	if (new_array != NULL)
	{
		i = 0;
		while (i < len)
		{
			str_len = ft_strlen(arr[i]);
			new_array[i] = (char*)malloc(sizeof(char) * (str_len + 1));
			if (new_array[i] != NULL)
				ft_strcpy(new_array[i], arr[i]);
			i++;
		}
		new_array[i] = NULL;
	}
	return (new_array);
}
