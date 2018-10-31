#include "minishell.h"
#include "functions.h"
//#include <unistd.h>

void	print_args(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		ft_putchar(s[i++]);
	ft_putchar('\n');
}

int	arg_count(char **av)
{
	int i;

	i = 1;
	while (av[i])
		i++;
	return (i);
}

int		command_echo(char **av)
{
	int	x;
	int	n;

	n = arg_count(av);
	x = 1;
	if (n == 2)
	{
		while (av[x] != NULL)
		{
			print_args(av[x]);
			++x;
			if (av[x] != NULL)
				ft_putchar(' ');
		}
	}
	else if (n > 2)
		print_args(av[1]);
	return (1);
}
