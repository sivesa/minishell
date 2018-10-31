/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 13:31:57 by ssandla           #+#    #+#             */
/*   Updated: 2017/09/02 13:32:00 by ssandla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void	ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = (NULL);
	}
}

void	check_char(char c)
{
	if (c == 'a')
		putchar('\a');
	else if (c == 'b')
		putchar('\b');
	else if (c == 'f')
		putchar('\f');
	else if (c == 'n')
		putchar('\n');
	else if (c == 'r')
		putchar('\r');
	else if (c == 't')
		putchar('\t');
	else if (c == 'v')
		putchar('\v');
	else if (c == '\\')
		putchar('\\');
	else
	{
		putchar('\\');
		putchar(c);
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
			putchar(s[i]);
	}
}

char		command_echo(char *av)
{
	int	*options;
	int	end_option;
	int	i;
	int	x;

	if ((options = (int *)malloc(sizeof(int) * 2)) == NULL)
		return (1);
	end_option = 0;
	i = (-1);
	x = 0;
	while (av != NULL)
	{
		if (x){}
		print_args(av, &end_option, options);
		++x;
		if (av != NULL && end_option == 1)
			putchar(' ');
	}
	if (options[0] == 0)
		putchar('\n');
	ft_memdel((void **)&options);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc && argv != NULL)
	{
		if (strcmp(argv[0], "./a.out"))
			command_echo(argv[1]);
		else
			printf("does not match");
	}
	return (0);
}
