/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:24:11 by ssandla           #+#    #+#             */
/*   Updated: 2017/11/18 12:24:23 by ssandla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"arrays.h"
#include	"functions.h"
#include	"minishell.h"

int		command_setenv(char **argv, char ***env)
{
	if (argv[1] != NULL)
	{
		if (argv[2] != NULL)
			*env = ft_setenv(argv[1], argv[2], *env);
		else
			*env = ft_setenv(argv[1], "", *env);
	}
	else
		ft_puterror("setenv: Too few arguments.\n");
	return (1);
}
