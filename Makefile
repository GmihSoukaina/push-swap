C_Compiler = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = Func/push_swap.h
HEADER_bns = Func_bns/checker.h

NAME = push_swap
BONUS_NAME = checker

Funs =  Func/helper_function.c Func/operation_push.c Func/helpr_function.c Func/algo_sort.c Func/func_utils_linkd_list.c Func/parsing.c Func/ft_split.c Func/operation_rotate.c Func/operation_reverse_rotate.c Func/operation_swap.c Func/push_swap.c
Funs_bn =  Func_bns/checker.c Func_bns/ft_split_bonus.c Func_bns/func_utils_linkd_list_bonus.c Func_bns/get_next_line_bonus.c Func_bns/get_next_line_utils_bonus.c Func_bns/helpr_function_bonus.c Func_bns/operation_push_bonus.c Func_bns/operation_reverse_rotate_bonus.c Func_bns/operation_rotate_bonus.c Func_bns/operation_swap_bonus.c Func_bns/parsing_bonus.c

OFuns = $(Funs:.c=.o)
OFuns_bn = $(Funs_bn:.c=.o)

all: $(NAME)

bonus: $(BONUS_NAME)


$(NAME): $(OFuns)
	@$(C_Compiler) $(CFLAGS) -o $(NAME) $(OFuns)

$(BONUS_NAME): $(OFuns_bn)
	@$(C_Compiler) $(CFLAGS) -o $(BONUS_NAME) $(OFuns_bn)

Func/%.o: Func/%.c $(HEADER)
	@$(C_Compiler) $(CFLAGS) -c $< -o $@

Func_bns/%.o: Func_bns/%.c $(HEADER_bns)
	@$(C_Compiler) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OFuns) $(OFuns_bn)

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: clean
