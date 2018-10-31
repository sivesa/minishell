/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:24:29 by ssandla           #+#    #+#             */
/*   Updated: 2017/11/18 12:24:32 by ssandla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"functions.h"
#include	"arrays.h"
#include	"minishell.h"

int		command_unsetenv(char **argv, char ***env)
{
	if (argv[1] != NULL)
	{
		*env = ft_unsetenv(argv[1], *env);
	}
	else
		ft_puterror("unsetenv: Too few arguments.\n");
	return (1);
}
