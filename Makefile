

NAME = event

SRC = ft_cmp.c \
		ft_strlen.c \
		game_handler.c \
		main.c \
		read_file.c \
		ft_lowercase.c \
		rainbow.c \
		ft_isalpha.c

OBJ_DIR = OBJ
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CC = gcc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3

READLINELIB = -lreadline

REMOVE = rm -f

COMPILE = gcc $(CFLAGS) -o $(NAME) -I ./lib -L. $(LIB) $(READLINELIB)

LDFLAGS		= -L/${HOME}/.brew/opt/readline/lib
CPPFLAGS	= -I/${HOME}/.brew/opt/readline/include

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILE) $(OBJ) ${LDFLAGS} ${CPPFLAGS} -L. $(LIB)

$(OBJ_DIR)/%.o:%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS) ${CPPFLAGS} -I./lib -o $@ $<

clean:
	$(REMOVE) $(OBJ)

fclean: clean
	$(REMOVE) -r $(OBJ_DIR)
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re
