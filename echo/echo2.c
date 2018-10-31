void	opt(char **av, char *tab)
{
	int	i;
	int	y;
	int	bo;

	i = 1;
	ft_bzero(tab, 3);
	while (av[i] != NULL && av[i][0] == '-')
	{
		y = 0;
		if (av[i][y] == '-')
			bo = test_opt(av, tab, y, i);
		if (bo == 1)
		{
			ft_putstr(av[i]);
			if (av[i + 1] != NULL && tab[2] != 's')
			ft_putchar(' ');
		}
		i++;
	}
}

void	charactors(char c, char *tab)
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
}

void	my_put_e(char *str, char *tabb, t_env *env)
{
	int	i;
	int	add;

	i = 0;
	while (str[i] != '\0')
	{
		add = write_var_env(str, i, env);
		i = i + add;
		if (str[i] == '\\')
		{
			charactors(str[i + 1], tabb);
			i++;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}

int		check_man_echo(char **av)
{
	if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
	{
		my_man("echo");
		return (0);
	}
	return (-1);
}

int		command_echo(char **av, t_env *env)
{
	char		tabb[3];
	int		i;

	if (av[1] == NULL || check_man_echo(av) == 0)
		return (0);
	i = 1;
	opt(av, tabb);
	while (av[i][0] == '-' && av[i + 1] != NULL)
		i++;
	if (av[i][0] == '-')
		i++;
	while (av[i] != NULL)
	{
		if (tabb[0] == 'E' || tabb[0] == '\0')
		my_put_echo(av[i], env);
		else if (tabb[0] == 'e')
		my_put_e(av[i], tabb, env);
		i++;
		if (av[i] != NULL && tabb[2] != 's')
		my_putchar(' ', 1);
	}
	if (tabb[1] != 'n')
		my_putchar('\n', 1);
	return (0);
}
