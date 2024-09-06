# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvitale <lvitale@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 13:06:56 by lvitale           #+#    #+#              #
#    Updated: 2024/01/15 11:29:35 by lvitale          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
ORANGE=\033[38;2;255;165;0m
NC=\033[0m 

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -IHeaders

OBJ_DIR = obj

SOURCE = 	game/controls.c \
			game/errors.c	\
			game/graphics.c	\
			game/map.c		\
			game/so_long.c	\
			game/valid_map.c\
			get_next_line/get_next_line.c 	\
			get_next_line/get_next_line_utils.c	\
			printf/ft_printf.c \
			printf/ft_putchar_pf.c \
			printf/ft_putnbr_pf.c \
			printf/ft_putnbrbase_pf.c \
			printf/ft_putptr_pf.c \
			printf/ft_putstr_pf.c \
			printf/ft_putunsigned_pf.c \

OBJ = $(SOURCE:%.c=$(OBJ_DIR)/%.o)
		
LIBRARY = -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX_PATH = minilibx/

TOTAL_FILES 	:= $(words $(SOURCE))
CURRENT_FILE 	:= 0

define progress_bar_so_long
    @$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
    @printf "\r$(YELLOW)Compiling So_long... [%-$(TOTAL_FILES)s] %d/%d $(NC)" $$(for i in $$(seq 1 $(CURRENT_FILE)); do printf "#"; done) $(CURRENT_FILE) $(TOTAL_FILES)
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES) ]; then echo ""; fi
endef

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	$(call progress_bar_so_long)

all: $(MINILIBX) $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)Linking objects to create executable...$(NC)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBRARY) -o $(NAME) 
	@echo "$(BLUE)Executable $(NAME) created!$(NC)"

$(MINILIBX):
	@echo "$(YELLOW)Compiling Minilibx...$(NC)"
	@$(MAKE) -C $(MINILIBX_PATH)

clean:
	@echo "$(ORANGE)Cleaning objects for Minilibx...$(NC)"
	@$(MAKE) clean -C $(MINILIBX_PATH) > /dev/null
	@echo "$(GREEN)Cleaned objects Libft!$(NC)"
	@echo "$(ORANGE)Cleaning objects for So_long...$(NC)"
	@rm -f $(OBJ_DIR)*.o
	@echo "$(GREEN)Cleaned So_long objects!$(NC)"

fclean: clean
	@echo "$(ORANGE)Fully cleaning library for Minilibx...$(NC)"
	@$(MAKE) clean -C $(MINILIBX_PATH) > /dev/null
	@echo "$(BLUE)Fully cleaned Minilibx!$(NC)"
	@echo "$(ORANGE)Fully cleaning library for So_long...$(NC)"
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@echo "$(BLUE)Fully cleaned So_long!$(NC)"

re: fclean all

.PHONY: all clean fclean re