/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:25:03 by ssandla           #+#    #+#             */
/*   Updated: 2017/11/18 12:25:05 by ssandla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	"functions.h"
#include	"minishell.h"

int			command_cd(char **argv, char ***env)
{
	char		*path;

	if (argv[1] != NULL)
	{
		path = argv[1];
		if (chdir(path) != 0)
			ft_putstr("Error: Can't change dir\n");
	}
	else
	{
		if ((path = get_home_dir(*env)) != NULL && chdir(path) != 0)
			ft_putstr("Error: Can't change dir\n");
	}
	*env = ft_setenv("PWD", path, *env);
	return (1);
}
