# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryatan <ryatan@student.42singapore.sg      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/28 16:26:03 by ryatan            #+#    #+#              #
#    Updated: 2025/12/02 08:08:07 by ryatan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# variables
NAME = libftprintf.a
ARCHIVE = ar
ARCHIVE_FLAGS = rcs
COMPILER = cc
CFLAGS = -Wall -Werror -Wextra -Ilibft

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SOURCE_FILES = ft_printf.c formatter_extract.c formatter_checker.c \
			   formatter_validate.c print_functions.c formatter_translate.c

OBJECT_FILES = $(SOURCE_FILES:%.c=%.o)

TEST_FILE = test.c
EXEC = test

# rules
%.o: %.c
	$(COMPILER) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJECT_FILES)
	$(ARCHIVE) $(ARCHIVE_FLAGS) $(NAME) $(OBJECT_FILES)

# testing with an exe
$(EXEC): $(TEST_FILE) $(NAME) $(LIBFT)
	$(COMPILER) $(TEST_FILE) -L. -lftprintf -L$(LIBFT_DIR) -lft -o $(EXEC)

all: $(LIBFT) $(NAME) $(EXEC)

clean:
	rm -rf $(OBJECT_FILES)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME) $(EXEC)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY : all clean fclean re
