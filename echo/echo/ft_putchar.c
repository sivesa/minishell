/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 13:34:28 by ssandla           #+#    #+#             */
/*   Updated: 2017/09/02 13:34:30 by ssandla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "echo.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
