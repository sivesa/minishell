/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:53:55 by ssandla           #+#    #+#             */
/*   Updated: 2017/12/08 11:02:35 by ssandla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<unistd.h>
#include	<signal.h>
#include	"arrays.h"
#include	"functions.h"
#include	"minishell.h"

int		g_busy;

int		command_line(char ***env)
{
	char	buf[1024];
	int	size;

	ft_putstr("$>");
	while ((size = read(0, buf, 1024)) > 0)
	{
		if (buf[size - 1] == '\n')
		{
			buf[size] = '\0';
			execute_command(buf, env);
			ft_putstr("$>");
		}
		else
		{
			while ((size = read(0, buf, 1024)) > 0);
			ft_putstr("Error: Command can contain only 1024 characters\n");
		}
	}
	if (size == 0)
		ft_free_array(*env);
	return (size);
}

//signal problems: ToBeFixed
void		signal_handler_ctrl_c(int signal)
{
	g_busy = 0;
	ft_putchar('\n');
	if (signal && !g_busy)
		ft_putstr("$>");
}

int		main(int argc, char **argv, char **env)
{
	char		**ft_env;
	int		options;

	g_busy = 0;
	if ((options = manage_options(argc, argv)) >= 0)
	{
		ft_env = ft_array_from_array(env);
		signal(SIGINT, signal_handler_ctrl_c);
		while (command_line(&ft_env) > 0);
	}
	return (0);
}
