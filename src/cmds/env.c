/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:24:54 by ssandla           #+#    #+#             */
/*   Updated: 2017/11/18 12:24:56 by ssandla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"functions.h"
#include	"arrays.h"
#include	"minishell.h"

int		command_env(char **argv, char ***env)
{
	if (argv[1] != NULL)
		ft_puterror("env: didn't suppose to have argument(s).\n");
	else
		ft_print_array(*env);
	return (1);
}
