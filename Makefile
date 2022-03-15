### ---   ---   ---         ---   ---   --- ###
#             PROJECT COMPILATION             #
### ---   ---   ---         ---   ---   --- ###

CC	= gcc
CFLAGS	= -Wall -Werror -Wextra -g3 -fsanitize=address

### ---   ---   ---         ---   ---   --- ###
#               PROJECT PATHS                 #
### ---   ---   ---         ---   ---   --- ###

INCS_PATH			= include/
SRCS_PATH			= src/
LIBFT_PATH			= libft/

### ---   ---   ---         ---   ---   --- ###
#               PROJECT FILES                 #
### ---   ---   ---         ---   ---   --- ###

NAME			= push_swap
CHECKER			= checker
LIBFT		= $(LIBFT_PATH)/libft.a

MANDATORY_FILES	=	mandatory/main.c \
					mandatory/merge_sort.c \
					mandatory/parse_numbers.c \
					mandatory/calm_down.c \
					mandatory/stack_utils.c \
					mandatory/chamber_algorithm.c \
					mandatory/stack_algorithm.c \
					mandatory/stack_algo_utils.c
					

COMMON_FILES	=	common/basic_movements.c \
					common/combo_movements.c \
					common/basic_utils.c

BONUS_FILES		=	bonus/main.c

MAND_OBJS = $(MANDATORY_FILES:%.c=bin/%.o)
COMM_OBJS = $(COMMON_FILES:%.c=bin/%.o)
BONUS_OBJS = $(BONUS_FILES:%.c=bin/%.o)

PS_OBJS = $(MAND_OBJS) $(COMM_OBJS)
CHECK_OBJS = $(BONUS_OBJS) $(COMM_OBJS)


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

$(NAME): $(LIBFT) $(PS_OBJS)
	@echo $(PURPLE)"[Creating $(NAME) "$(PURPLE)"]"$(WHITE)
	$(CC) $(CFLAGS) $(PS_OBJS) $(LIBFT) -I $(INCS_PATH) -I $(LIBFT_PATH) -o $(NAME)

bonus: $(CHECKER)

$(CHECKER): $(LIBFT) $(CHECK_OBJS)
	@echo $(PURPLE)"[Creating $(CHECKER) "$(PURPLE)"]"$(WHITE)
	$(CC) $(CFLAGS) $(CHECK_OBJS) $(LIBFT) -I $(INCS_PATH) -I $(LIBFT_PATH) -o $(CHECKER)

$(LIBFT):
	@echo $(PURPLE)"[Make Libft]"$(WHITE)
	@make -C $(LIBFT_PATH)

bin/bonus/%.o: src/bonus/%.c
	@echo $(BLUE)"[Compilation]"$(WHITE)": $< "
	@mkdir -p bin/bonus
	$(CC) $(CFLAGS) -I $(INCS_PATH) -I $(LIBFT_PATH) -c $< -o $@

bin/mandatory/%.o: src/mandatory/%.c
	@echo $(BLUE)"[Compilation]"$(WHITE)": $< "
	@mkdir -p bin/mandatory
	$(CC) $(CFLAGS) -I $(INCS_PATH) -I $(LIBFT_PATH) -c $< -o $@

bin/common/%.o: src/common/%.c
	@echo $(BLUE)"[Compilation]"$(WHITE)": $< "
	@mkdir -p bin/common
	$(CC) $(CFLAGS) -I $(INCS_PATH) -I $(LIBFT_PATH) -c $< -o $@

clean:
	@echo $(RED)"[Deleting Object Files]"$(WHITE)
	@rm -rf bin
	@echo $(RED)"[Deleting Libft Object Files]"$(WHITE)
	@make clean -C $(LIBFT_PATH)

fclean: clean 
	@echo $(RED)"[Deleting $(NAME)]"$(WHITE)
	@rm -f $(NAME)
	@echo $(RED)"[Deleting $(NAME)]"$(WHITE)
	@rm -f $(CHECKER)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

