CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = push_swap
SRC_DIR = src/
SRC = main.c swap.c push.c rotate.c rrotate.c smallsort.c stack_management.c supersort.c chunksort.c check_arguments.c
OBJ_DIR = objs/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

all: libft $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) libft/*.o
	@ echo "Push_swap compiled"

bonus: libft $(BONUS_OBJ)
	@$(CC) $(FLAGS) -o $(BONUS_NAME) $(BONUS_OBJ) libft/*.o
	@ echo "Checker compiled"

libft:
	@make -C libft/

clean:
	@$(RM) $(OBJ) $(BONUS_OBJ)
	@make -C libft/ clean

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all libft clean fclean re 