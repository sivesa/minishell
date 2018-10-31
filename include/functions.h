#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_puterror(char *str);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, int n);
int	ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, int n);
int	ft_strncmp(char *str1, char *str2, int n);
int	ft_getnbr(char *str);
int	ft_strcmp(char *s1, char *s2);
char	*merge_strings(char *str, char *plus, int n);

#endif
