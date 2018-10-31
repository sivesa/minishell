#include "echo.h"

void	check_char(char c)
{
	if (c == 'a')
		ft_putchar('\a');
	else if (c == 'b')
		ft_putchar('\b');
	else if (c == 'f')
		ft_putchar('\f');
	else if (c == 'n')
		ft_putchar('\n');
	else if (c == 'r')
		ft_putchar('\r');
	else if (c == 't')
		ft_putchar('\t');
	else if (c == 'v')
		ft_putchar('\v');
	else if (c == '\\')
		ft_putchar('\\');
	else
	{
		ft_putchar('\\');
		ft_putchar(c);
	}
}

int		check_options(char *s, int *option_n, int *option_control)
{
	int	i;

	i = 1;
	if (s[0] == '-')
	{
		while ((s[i] == 'e' || s[i] == 'E' || s[i] == 'n') && s[i] != '\0')
			++i;
		if (s[i] != '\0')
			return (1);
		i = 0;
		while (s[++i] != '\0')
		{
			if (s[i] == 'n')
				*option_n = 1;
			else if (s[i] == 'e')
				*option_control = 1;
			else if (s[i] == 'E')
				*option_control = 0;
		}
		return (0);
	}
	return (1);
}

void	print_args(char *s, int *end_option, int *options)
{
	int	i;

	i = (-1);
	if (*end_option == 0)
		*end_option = check_options(s, options, (options + 1));
	while (s[++i] != '\0' && *end_option == 1)
	{
		if (s[i] == '\\' && options[1] == 1)
		{
			++i;
			if (s[i] != '\0')
				check_char(s[i]);
		}
		else
			ft_putchar(s[i]);
	}
}

int		command_echo(char **av)
{
	int	*options;
	int	end_option;
	int	i;
	int	x;

	if ((options = (int *)ft_memalloc(sizeof(int) * 2)) == NULL)
		return (1);
	end_option = 0;
	i = (-1);
	x = 0;
	while (av[1][x] != NULL)
	{
		print_args(av[1][x], &end_option, options);
		++x;
		if (av[1][x] != NULL && end_option == 1)
			ft_putchar(' ');
	}
	if (options[0] == 0)
		ft_putchar('\n');
	ft_memdel((void **)&options);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc && argv != NULL)
	{
		if (strcmp(argv[0], "a.out"))
			command_echo(argv);
		else
			printf("does not match");
	}
	return (0);
}
