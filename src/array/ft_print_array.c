/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:26:17 by ssandla           #+#    #+#             */
/*   Updated: 2017/11/18 12:26:20 by ssandla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"functions.h"

void		ft_print_array(char **arr)
{
	int		i;

	i = 0;
	while (arr[i] != NULL)
	{
		ft_putstr(arr[i]);
		ft_putchar('\n');
		i++;
	}
}
