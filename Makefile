NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

DIR_L = srcs/

INCLUDES = -I includes/ -I libft/

LIST = 		                    ft_printf.c \
                                ft_parse.c \
                                ft_printf_type_s.c \
                                ft_printf_type_c.c \
                                ft_printf_type_p.c \
                                ft_printf_type_d.c \
                                ft_printf_type_x.c \
                                ft_printf_type_u.c \
                                ft_printf_utils.c \
                                ft_check_minus.c \
                                ft_printf_utils_p.c \
                                ft_lst.c


OBJS =$(SRCS:.c=.o)

SRCS = $(addprefix $(DIR_L), $(LIST))

all: $(NAME)

$(NAME): my_lib $(OBJS)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

my_lib:
	make -C $(LIBFT)

%.o: %.c includes/ft_printf.h
	gcc -g $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: fclean re norme all clean