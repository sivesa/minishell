/*
** exit.c for  in /home/romain.pillot/projects/PSU_2016_minishell1/src/built-in
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Mar  8 13:38:50 2017 romain pillot
** Last update Sat May 20 20:00:03 2017 romain pillot
*/

#include "builtin.h"
#include <stdlib.h>
#include "util.h"
#include <unistd.h>
#include <math.h>

static int	convert_octal(int octal)
{
  int		decimal;
  int		i;

  decimal = (i = 0);
  while (octal)
    {
      decimal += (octal % 10) * pow(8, i++);
      octal /= 10;
    }
  return (decimal);
}

static char	format_octal(char *str, int *i)
{
  int		j;
  int		octal;
  int		limit;

  limit = (octal = (j = 0));
  while (limit++ <= 3 && str[j] >= '0' && str[j] <= '9' && ++j && ++(*i))
    octal = octal * 10 + str[j - 1] - '0';
  return (octal ? convertOctalToDecimal(octal) : 0);
}

static char	format_escaped(char c)
{
  return (c == 'n' ? '\n' :
	  c == 't' ? '\t' :
	  c == 'a' ? '\a' :
	  c == 'b' ? '\b' :
	  c == 'e' ? '\e' :
	  c == 'f' ? '\f' :
	  c == 'r' ? '\r' :
	  c == 'v' ? '\v' : 0);
}

void	command_echo(char **args)
{
	char	*str;
	int	i;
	char	format;
	bool	display_return;

	display_return = !equalstr(args[1], "-n");
	str = joinstr(args + (display_return ? 1 : 2), " ");
	i = -1;
	while (str && str[++i])
	{
		if (str[i] == '\\')
			if (str[i + 1] == '0')
				ft_putchar(format_octal(str + i + 1, &i));
			else if ((format = format_escaped(str[i + 1])) && ++i)
				ft_putchar(format);
			else
				write(STDOUT_FILENO, str + i++, 2);
		else
			ft_putchar(str[i]);
	}
	if (display_return)
		ft_putchar('\n');
	//shell->status = EXIT_SUCCESS;
	safe_free(str);
}
