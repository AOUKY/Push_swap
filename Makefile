MFILES = push_swap.c file.c helper.c linked_lst_func.c operations.c operations2.c setup.c sorting.c check_plus.c ft_split.c 
BFILES = operations.c check_plus.c helper.c setup.c operations2.c checker.c add_for_checkr.c ft_split.c linked_lst_func.c file.c
NAME = push_swap
BNAME = checker
CC = gcc
GFLAGS = -Wall -Werror -Wextra
GNL = Get_Next_Line/get_next_line.c Get_Next_Line/get_next_line_utils.c
PRINTF =  ft_printf/libftprintf.a
DPRINT = ft_printf

all: $(NAME)

$(PRINTF):
	@make -C $(DPRINT) 
	
$(NAME): $(MFILES) $(PRINTF)
	$(CC) $(GFLAGS) $(MFILES) $(PRINTF) -o $@

$(BNAME): $(BFILES) $(PRINTF) $(GNL)
	$(CC) $(GFLAGS) $(BFILES) $(PRINTF) $(GNL) -o $(BNAME)

bonus: $(BNAME)
	
clean:
	@make -C $(DPRINT) fclean

fclean: clean
	rm -rf push_swap checker

re: fclean all