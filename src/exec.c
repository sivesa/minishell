#include	<stdlib.h>
#include	<sys/types.h>
#include	<unistd.h>
#include	"functions.h"
#include	"arrays.h"
#include	"minishell.h"

#include <stdio.h>

int		control_default_cmd(char **argv, char ***env)
{
	if (ft_strcmp(argv[0], "exit") == 0)
		return (command_exit(argv, *env));
	else  if (ft_strcmp(argv[0], "setenv") == 0)
		return (command_setenv(argv, env));
	else  if (ft_strcmp(argv[0], "unsetenv") == 0)
		return (command_unsetenv(argv, env));
	else  if (ft_strcmp(argv[0], "env") == 0)
		return (command_env(argv, env));
	else  if (ft_strcmp(argv[0], "cd") == 0)
		return (command_cd(argv, env));
	else  if (ft_strcmp(argv[0], "echo") == 0)
		return (command_echo(argv));
	return (0);
}

int		child(char **argv, char **env)
{
	if (execve(get_bin_path(argv[0], env), argv, env) < 0)
	{
		ft_puterror(argv[0]);
		ft_puterror(": command not found\n");
		return (0);
	}
	return (1);
}

int		execute_command(char *cmd, char ***env)
{
	char			**argv;
	pid_t		pid;
	pid_t		wpid;
	int			status;
	
	status = 1;
	if ((argv = ft_parse_args(cmd, *env)) != NULL){}
	if (!control_default_cmd(argv, env))
	{
		if ((pid = fork()) >= 0)
		{
			if (pid == 0)
			{
				if (!child(argv, *env))
				{
					ft_free_array(argv);
					exit(EXIT_FAILURE);
				}
				exit(EXIT_SUCCESS);
			}
			else
			{
				ft_free_array(argv);
				while ((wpid = wait(&status)) > 0);
			}
		}
	}
	return (-1);
}
