# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: math <math@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 18:22:37 by math42            #+#    #+#              #
#    Updated: 2025/04/06 12:55:45 by math             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = cpp
SRCSDIR     = .
INCLUDES    = .
OBJDIR      = .obj

SRCS        = $(wildcard $(SRCSDIR)/*.cpp)
OBJS        = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98

EX_NAME = $(notdir $(CURDIR))

ifeq ($(EX_NAME), ex00)
	CFLAGS += -DEX00
endif
ifeq ($(EX_NAME), ex01)
	CFLAGS += -DEX01
endif
ifeq ($(EX_NAME), ex02)
	CFLAGS += -DEX02
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	find . -name "*.o" -exec rm -f {} +
	rm -rf $(NAME)
	rm -rf .vscode
	

re: fclean all

.PHONY: all clean fclean re test

