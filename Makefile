SRCS	=	src/minishell.c \
		src/env.c \
		src/path.c \
		src/exec.c \
		src/args.c \
		src/options.c \
		src/cmds/cd.c \
		src/cmds/setenv.c \
		src/cmds/unsetenv.c \
		src/cmds/env.c \
		src/cmds/exit.c \
		src/cmds/echo.c \
		src/array/ft_add_to_array.c \
		src/array/ft_array_from_array.c \
		src/array/ft_remove_from_array.c \
		src/array/ft_split_string.c \
		src/array/ft_print_array.c \
		src/array/ft_free_array.c \
		src/array/ft_array_length.c \
		src/func/ft_putchar.c \
		src/func/ft_putstr.c \
		src/func/ft_puterror.c \
		src/func/ft_strcat.c \
		src/func/ft_strlen.c \
		src/func/ft_strcpy.c \
		src/func/ft_strncpy.c \
		src/func/ft_strncat.c \
		src/func/ft_strncmp.c \
		src/func/ft_strcmp.c \
		src/func/ft_merge_strings.c \
		src/func/ft_getnbr.c \

CFLAGS	+=	-Wall -Werror -Wextra
CFLAGS	+=	-I./include

NAME	=	minishell

OBJS	=	$(SRCS:.c=.o)

CC	=	gcc

RM	=	rm -f


all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)
#manage_options
re:		fclean all

.PHONY:		re all fclean clean
