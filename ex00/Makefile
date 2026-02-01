NAME    = rush-02
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = clean_dict.c error.c extract_number_ext.c \
			ft_strncpy.c ft_write_len.c ft_write_number.c \
			get_args.c main.c read_file.c sort_dict.c utils.c \
			validation.c verification.c write.c
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re