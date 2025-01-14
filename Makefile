NAME = push_swap

BONUS = checker

CC = cc

FLAGS = -Wall -Wextra -Werror

LIBFT = ./Libft/libft.a

LIBFTDIR = ./Libft

SRC = check_parameters.c error_msg.c op_to_list.c free_stuff.c valid_int.c \
	moves_push.c moves_swap.c moves_rotate.c moves_reverse_rotate.c \
	check_sort_list.c init_data.c sort_algorithm.c make_moves.c both_stack_op.c \
	utils.c positions.c main.c

OBJ = $(SRC:%.c=%.o)

B_SRC = check_parameters.c error_msg.c op_to_list.c free_stuff.c valid_int.c \
	moves_push.c moves_swap.c moves_rotate.c moves_reverse_rotate.c \
	check_sort_list.c init_data.c both_stack_op.c \
	utils.c get_next_line.c checker.c checker_util.c

B_OBJ = $(B_SRC:%.c=%.o)

all: ${NAME}

bonus: ${BONUS}

${NAME}: $(OBJ)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(FLAGS) -lm $(SRC) $(LIBFT) -o $(NAME)

${BONUS}: $(B_OBJ)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(FLAGS) $(B_OBJ) $(LIBFT) -o $(BONUS)

clean:
	$(MAKE) clean -C ./Libft
	@rm -rf $(OBJ) $(B_OBJ)

fclean: clean
	$(MAKE) fclean -C ./Libft
	@rm -rf $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
