/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 13:30:05 by ssandla           #+#    #+#             */
/*   Updated: 2017/09/02 13:30:07 by ssandla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "echo.h"

void	*ft_memalloc(size_t size)
{
	void	*ret;

	if (size == 0)
		return (NULL);
	if (!(ret = (void*)(malloc(size))))
		return (NULL);
	ft_bzero(ret, size);
	return (ret);
}
