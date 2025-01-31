# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nogura <nogura@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/24 18:21:33 by nogura            #+#    #+#              #
#    Updated: 2024/12/23 17:47:26 by nogura           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target name
NAME        = libftprintf.a

# Tool and flag 
AR          = ar
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# Directory
SRCDIR      = src
OBJDIR      = obj
SRCS        = $(wildcard $(SRCDIR)/*.c)
OBJS        = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
LIBFT_DIR   = Libft
INCLUDES    = -I include -I $(LIBFT_DIR)/include

# Library
LIBFT_LIB   = $(LIBFT_DIR)/libft.a

# Multiple processing
CPU_COUNT := $(shell nproc)
JOBS ?= $(CPU_COUNT)

# Target roule
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB)
	@cp $(LIBFT_LIB) $(NAME)
	@$(AR) r $(NAME) $(OBJS)

# Compile source files to object files, but not linking
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR) -j $(JOBS)

# Clean up roule
clean:
	@rm -f $(OBJDIR)/*.o
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
