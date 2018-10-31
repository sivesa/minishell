#ifndef	MINISHELL_H
# define MINISHELL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int	execute_command(char *command, char ***env);
int	manage_options(int argc, char **argv);

char	*get_bin_path(char *filename, char **env);
char	*get_home_dir(char **env);

char	**ft_parse_args(char *str, char **env);

int	ft_getenv(char *name, char **env);
char	**ft_setenv(char *name, char *value, char **env);
char	**ft_unsetenv(char *name, char **env);

void	print_args(char *s);

int	command_exit(char **argv, char **env);
int	command_setenv(char **argv, char ***env);
int	command_unsetenv(char **argv, char ***env);
int	command_cd(char **argv, char ***env);
int	command_env(char **argv, char ***env);
int	command_echo(char **av);

#endif
