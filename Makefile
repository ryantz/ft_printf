# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryatan <ryatan@student.42singapore.sg      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/28 16:26:03 by ryatan            #+#    #+#              #
#    Updated: 2025/11/28 23:00:28 by ryatan           ###   ########.fr        #
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

SOURCE_FILES = ft_printf.c 

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
$(EXEC): $(OBJECT_FILES) $(NAME) $(LIBFT)
	$(COMPILER) $(TEST_FILE) $(OBJECT_FILES) -L. -lftprintf -L$(LIBFT_DIR) -lft -o $(EXEC)

all: $(LIBFT) $(NAME) $(EXEC)

clean:
	rm -rf $(OBJECT_FILES)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY : all clean fclean re
