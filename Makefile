CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
BONUS_NAME = checker
PRINTF = ft_printf/ftprintf.a

CFS = checkers.c str_to_int.c ft_split.c instructions.c sort.c\
 		main.c push_args.c stacks.c ft_substr.c nodes.c update_stacks.c\

BFS = push_swap_checker/main.c push_swap_checker/get_next_line/get_next_line.c\
		push_swap_checker/get_next_line/get_next_line_utils.c push_swap_checker/nodes.c\
		push_swap_checker/checkers.c push_swap_checker/push_args.c push_swap_checker/ft_split.c push_swap_checker/ft_substr.c\
		push_swap_checker/stacks.c push_swap_checker/str_to_int.c push_swap_checker/instructions.c\

all: $(NAME)

$(NAME): $(CFS) $(PRINTF)
	$(CC) $(CFLAGS) $^ -o $@

$(PRINTF):
	make all -C ft_printf

bonus: $(BFS)
	$(CC) $(CFLAGS) $^ -o $(BONUS_NAME)

clean:
	make clean -C ft_printf


fclean: clean
	make fclean -C ft_printf
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	
re: fclean all
	
