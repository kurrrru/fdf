NAME		= fdf
SRCS_CHECK	= is_valid_extension.c
SRCS_ERROR	= error_argc.c error_extension.c
SRCS		= main.c $(SRCS_ERROR) $(SRCS_CHECK)
OBJS		= $(SRCS:.c=.o)
LIBFTDIR	= libft
LIBFT		= libft.a
CC			= cc
LIBM_FLAGS	= -lm
CFLAGS		= -Wall -Wextra -Werror $(LIBM_FLAGS)

.DEFAULT_GOAL = all

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTDIR)/$(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(LIBFTDIR)/$(LIBFT):
	make -C $(LIBFTDIR)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)
	make -C $(LIBFTDIR) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
