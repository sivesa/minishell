#ifndef ARRAY_H
# define ARRAY_H

char	**ft_array_from_array(char **arr);
char	**ft_split_string(char *str, char *separator,
			  int quotes_mode);
char	**ft_add_to_array(char *str, char **arr);
void	ft_print_array(char **arr);
int	ft_free_array(char **arr);
int	ft_array_length(char **arr);
char	**ft_remove_from_array(int rem, char **arr);

#endif
