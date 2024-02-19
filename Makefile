NAME = GNL
NAME_BONUS = GNL_BONUS

CC = gcc
CFLAGS = -Wall -Wextra -Werror

DEPS = ${OBJS:.o=.d}

INC = ./includes/get_next_line.h
BONUS_INC = ./includes/get_next_line_bonus.h

SRC_PATH = ./srcs
OBJS_PATH = ./objs

SRCS = get_next_line.c get_next_line_utils.c
BONUS_SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c

SRC = $(addprefix $(SRC_PATH)/, $(SRCS))
BONUS_SRC = $(addprefix $(SRC_PATH)/, $(BONUS_SRCS))

OBJS = $(addprefix $(OBJS_PATH)/, $(SRCS:.c=.o))
BONUS_OBJS = $(addprefix $(OBJS_PATH)/, $(BONUS_SRCS:.c=.o))

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m
YELLOW = \033[33m

mandatory: $(NAME)

bonus: $(NAME_BONUS)

all: $(NAME) $(NAME_BONUS)

$(NAME): $(OBJS) $(INC)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Compilation complete! \n$(YELLOW)$(NAME) is ready to execute.$(NC)"

$(NAME_BONUS): $(BONUS_OBJS) $(BONUS_INC)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME_BONUS)
	@echo "$(GREEN)Compilation complete! \n$(YELLOW)$(NAME_BONUS) is ready to execute with bonuses.$(NC)"

$(OBJS_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	@mkdir -p $(OBJS_PATH)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@
	@echo "$(GREEN)Compiled:$(NC) $<"

$(OBJS_PATH)/%.o: $(SRC_PATH)/%.c $(BONUS_INC)
	@mkdir -p $(OBJS_PATH)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@
	@echo "$(GREEN)Compiled:$(NC) $<"

clean:
	@rm -rf $(OBJS_PATH)
	@echo "$(RED)Cleaned up object files.$(NC)"

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "$(RED)Cleaned up executables.$(NC)"

re: fclean all

-include $(DEPS)

.PHONY: mandatory bonus all clean fclean re
