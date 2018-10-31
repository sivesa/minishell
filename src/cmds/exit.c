/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:24:44 by ssandla           #+#    #+#             */
/*   Updated: 2017/11/18 12:24:47 by ssandla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"arrays.h"
#include	"functions.h"
#include	"minishell.h"

int		command_exit(char **argv, char **env)
{
	int		status;

	status = 0;
	if (argv[1] != NULL)
		status = ft_getnbr(argv[1]);
	ft_free_array(argv);
	ft_free_array(env);
	exit(status);
	return (1);
}
