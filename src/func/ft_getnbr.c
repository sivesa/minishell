/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:27:29 by ssandla           #+#    #+#             */
/*   Updated: 2017/11/18 12:34:17 by ssandla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"functions.h"

int		ft_getnbr(char *nbr)
{
	int		int_nbr;
	char		digit;
	char		last_digit;
	int		sign;
	
	int_nbr = 0;
	sign = 1;
	last_digit = '\0';
	while (*nbr != '\0')
	{
		digit = *nbr;
		if ((digit - '0') >= 0 && (digit - '0') <= 9)
		{
			int_nbr = int_nbr * 10 + digit - '0';
			if (int_nbr < 0)
				return (0);
		}
		else if (digit == '-')
			sign = -sign;
		else if ((last_digit - '0') >= 0 &&  (last_digit - '0') <= 9)
			return (int_nbr * sign) ;
		last_digit = digit;
		nbr++;
	}
	return (int_nbr * sign);
}
