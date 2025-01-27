CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADERS = Func/push_swap.h

NAME = push_swap
Funs =  Func/helper_function.c Func/operation_push.c Func/helpr_function.c Func/algo_sort.c Func/func_utils_linkd_list.c Func/parsing.c Func/ft_split.c Func/operation_rotate.c Func/operation_reverse_rotate.c Func/operation_swap.c  Func/push_swap.c

OFuns = $(Funs:.c=.o)

all: $(NAME)

$(NAME): $(OFuns)
	@$(CC) $(CFLAGS) -o $(NAME) $(OFuns)

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OFuns)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean