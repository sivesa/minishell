#include	<stdlib.h>
#include	<stdio.h>
#include	"arrays.h"
#include	"functions.h"
#include	"minishell.h"

int		replace_variable(char **str, char **env)
{
	char		*value;
	int		value_len;
	int		name_len;
	int		i;

	name_len = ft_strlen((*str) + 1) + 1;
	if ((i = ft_getenv((*str) + 1, env)) >= 0)
	{
		value_len = ft_strlen(env[i] + name_len);
		value = (char*)malloc(sizeof(char) * (value_len + 1));
		if (value != NULL)
		{
			ft_strcpy(value, env[i] + name_len);
			free(*str);
			*str = value;
		}
	}
	return (0);
}

char		*get_variable_value(char *result, int *i, char *str, char **env)
{
	int		start;
	int		var_n;
	char		*search;
	char		name_len;

	start = *i + 1;
	*i = *i + 1;
	while ((str[*i] >= 'A' && str[*i] <= 'Z') || (str[*i] == '_') ||
	 (str[*i] >= 'a' && str[*i] <= 'z') ||
	 (str[*i] >= '0' && str[*i] <= '9'))
		*i = *i + 1;
	name_len = (*i) - start;
	search = (char*)malloc(sizeof(char) * (name_len + 1));
	if (search != NULL)
	{
		ft_strncpy(search, str + start, name_len);
		if ((var_n = ft_getenv(search, env)) > 0)
		{
			  free(search);
			  return (merge_strings(result, env[var_n] + name_len + 1,
						ft_strlen(env[var_n] + name_len + 1)));
		}
		free(search);
	}
	return (result);
}

int		replace_quotes(char **str, char **env, int doubled)
{
	int		i;
	int		last;
	char		*result;

	i = 1;
	last = 1;
	result = NULL;
	while ((*str)[i] != '\0'
	 && (*str)[i] != '\''
	 && (*str)[i] != '"')
	{
		if ((*str)[i] == '$' && doubled)
		{
			result = merge_strings(result, (*str) + last, i - last);
			result = get_variable_value(result, &i, *str, env);
			last = i;
		}
		i++;;
	}
	result = merge_strings(result, (*str) + last, ft_strlen(*str) - 1 - last);
	free(*str);
	*str = result;
	return (1);
}

void		replace_home_symbol(char **str, char **env)
{
	char		*result;
	char		*home_path;

	if ((home_path = get_home_dir(env)) != NULL)
	{
		result = NULL;
		result = merge_strings(result, home_path, ft_strlen(home_path));
		result = merge_strings(result, (*str) + 1, ft_strlen((*str) + 1));
		if (result != NULL)
		{
			free(*str);
			*str = result;
		}
	}
}

char		**ft_parse_args(char *str, char **env)
{
	char		**argv;
	int		i;

	if ((argv = ft_split_string(str, " \t\n", 1)) != NULL)
	{
		i = 0;
		while (argv[i] != NULL)
		{
			if (argv[i][0] == '$')
				replace_variable(&argv[i], env);
			else if (argv[i][0] == '~')
				replace_home_symbol(&argv[i], env);
			else if (argv[i][0] == '\'')
				replace_quotes(&argv[i], env, 0);
			else if (argv[i][0] == '"')
				replace_quotes(&argv[i], env, 1);
			i++;
		}
	}
	return (argv);
}
