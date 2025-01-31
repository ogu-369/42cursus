# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nogura <nogura@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 13:50:14 by nogura            #+#    #+#              #
#    Updated: 2024/12/23 17:47:10 by nogura           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libft.a
AR          = ar
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
SRCDIR      = src
OBJDIR      = obj
SRCS        = $(wildcard $(SRCDIR)/*.c)
OBJS        = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
INCLUDES    = -I include

# Target roule
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) r $(NAME) $(OBJS)

# Compile source files to object files, but not linking
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re