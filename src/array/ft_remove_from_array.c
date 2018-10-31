/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_from_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:26:30 by ssandla           #+#    #+#             */
/*   Updated: 2017/11/18 12:26:33 by ssandla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"functions.h"
#include	"arrays.h"

char		**copy_array_without(int rem, char **new_arr, char **arr, int len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (i != rem)
		{
			new_arr[j] = (char*)malloc(sizeof(char) * (ft_strlen(arr[i]) + 1));
			if (new_arr[j])
			{
				ft_strcpy(new_arr[j], arr[i]);
				j++;
			}
		}
		i++;
	}
	new_arr[j] = NULL;
	return (new_arr);
}

char		**ft_remove_from_array(int rem, char **arr)
{
	int		len;
	char		**new_arr;

	new_arr = NULL;
	if (arr != NULL)
	{
		len = ft_array_length(arr);
		new_arr = (char**)malloc(sizeof(char*) * (len));
		new_arr = copy_array_without(rem, new_arr, arr, len);
		ft_free_array(arr);
	}
	return (new_arr);
}

