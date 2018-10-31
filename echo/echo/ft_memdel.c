/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 13:31:57 by ssandla           #+#    #+#             */
/*   Updated: 2017/09/02 13:32:00 by ssandla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "echo.h"

void	ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = (NULL);
	}
}
