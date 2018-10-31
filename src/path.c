#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	"functions.h"
#include	"arrays.h"
#include	"minishell.h"

char		*try_path(char *filename, char *dir)
{
	int		total_len;
	char		*path;

	total_len = ft_strlen(filename) + ft_strlen(dir) + 2;
	path = (char*)malloc(sizeof(char) * total_len);
	if (path != NULL)
	{
		ft_strcpy(path, dir);
		ft_strcat(path, "/");
		ft_strcat(path, filename);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		path = NULL;
	}
	return (path);
}

char		*get_bin_path(char *filename, char **env)
{
	int		i;
	char		*path;
	char		**a_path;
	char		*p_bin;

	path = NULL;
	if ((i = ft_getenv("PATH", env)) >= 0)
		path = env[i] + 5;
	i = 0;
	if (path != NULL && (a_path = ft_split_string(path, ":", 1)) != NULL)
	{
		i = 0;
		while (a_path[i] != NULL)
		{
			if ((p_bin = try_path(filename, a_path[i])) != NULL)
			{
				ft_free_array(a_path);
				return (p_bin);
			}
			i++;
		}
	}
	return (filename);
}

char	*get_home_dir(char **env)
{
	int	i;

	if ((i = ft_getenv("HOME", env)) >= 0)
		return (env[i] + 5);
	return (NULL);
}
