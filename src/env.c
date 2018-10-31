#include	<stdlib.h>
#include	"functions.h"
#include	"arrays.h"
#include	"minishell.h"

int		ft_getenv(char *name, char **env)
{
	int		i;
	char		*search;
	int		name_len;

	name_len = ft_strlen(name) + 2;
	search = (char*)malloc(sizeof(char) * name_len);
	if (search != NULL)
	{
		ft_strcpy(search, name);
		ft_strcat(search, "=");
		i = 0;
		while (env[i] != NULL)
		{
			if (ft_strncmp(env[i], search, name_len) == 0)
			{
				free(search);
				return (i);
			}
			i++;
		}
		free(search);
	}
	return (-1);
}

char		**ft_setenv(char *name, char *value, char **env)
{
	int		i;
	int		total_len;
	char		*record;

	total_len = ft_strlen(name) + ft_strlen(value) + 2;
	record = (char*)malloc(sizeof(char) * total_len);
	if (record != NULL)
	{
		ft_strcpy(record, name);
		ft_strcat(record, "=");
		ft_strcat(record, value);
		if ((i = ft_getenv(name, env)) >= 0)
		{
			free(env[i]);
			env[i] = record;
		}
		else
			return (ft_add_to_array(record, env));
	}
	return (env);
}

char		**ft_unsetenv(char *name, char **env)
{
	int		i;

	if ((i = ft_getenv(name, env)) >= 0)
		env = ft_remove_from_array(i, env);
	return (env);
}

