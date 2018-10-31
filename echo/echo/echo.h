#ifndef ECHO_H
#define ECHO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	check_char(char c);
int	check_options(char *s, int *option_n, int *option_control);
void	print_args(char *s, int *end_option, int *options)
int	command_echo(char **av);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
void	ft_putchar(char c);
int	ft_strcmp(const char *s1, const char *s2);

#endif
