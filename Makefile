### ---   ---   ---         ---   ---   --- ###
#             PROJECT COMPILATION             #
### ---   ---   ---         ---   ---   --- ###

CC	= gcc
CFLAGS	= -Wall -Werror -Wextra #-g3 -fsanitize=address

### ---   ---   ---         ---   ---   --- ###
#               PROJECT PATHS                 #
### ---   ---   ---         ---   ---   --- ###

INCS_PATH			= include/
SRCS_PATH			= src/
BIN_PATH			= bin/
LIBFT_PATH			= libft/

### ---   ---   ---         ---   ---   --- ###
#               PROJECT FILES                 #
### ---   ---   ---         ---   ---   --- ###

NAME		= push_swap
LIBFT		= $(LIBFT_PATH)/libft.a

SRCS		=	main.c \
				merge_sort.c \
				parse_numbers.c \
				basic_movements.c \
				combo_movements.c \
				calm_down.c \
				stack_utils.c \
				chamber_algorithm.c \
				radix_algorithm.c \
				stack_algorithm.c \
				insertion_algorithm.c

OBJS = $(SRCS:%.c=bin/%.o)

### ---   ---   ---         ---   ---   --- ###
#              COLORS & EXTRAS :)             #
### ---   ---   ---         ---   ---   --- ###

RED		= '\033[1;31m'
GREEN	= '\033[1;32m'
PURPLE	= '\033[1;35m'
YELLOW	= '\033[1;33m'
WHITE	= '\033[1;37m'
BLUE	= '\033[1;34m'

### ---   ---   ---         ---   ---   --- ###
#                  GAME RULES                 #
### ---   ---   ---         ---   ---   --- ###

.PHONY: all re clean fclean bonus

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo $(PURPLE)"[Creating $(NAME) "$(PURPLE)"]"$(WHITE)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -I $(INCS_PATH) -I $(LIBFT_PATH) -o $(NAME)

$(LIBFT):
	@echo $(PURPLE)"[Make Libft]"$(WHITE)
	@make -C $(LIBFT_PATH)

bin/%.o: src/%.c
	@echo $(BLUE)"[Compilation]"$(WHITE)": $< "
	$(CC) $(CFLAGS) -I $(INCS_PATH) -I $(LIBFT_PATH) -c $< -o $@

clean:
	@echo $(RED)"[Deleting Object Files]"$(WHITE)
	@rm -rf $(OBJS)
	@echo $(RED)"[Deleting Libft Object Files]"$(WHITE)
	@make clean -C $(LIBFT_PATH)

fclean: clean 
	@echo $(RED)"[Deleting $(NAME)]"$(WHITE)
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

