# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfrankev <mfrankev@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 13:51:48 by mfrankev          #+#    #+#              #
#    Updated: 2017/02/18 19:12:50 by mfrankev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap

NAME_CH = checker

LIBFT = libft/libft.a

SRC_PS = stack_operations.c \
		stack_operattons_2.c \
		stack_operations_both.c \
        reading.c \
		sorting.c \
		stack_operations_3.c \
		sort_three.c \
		optimize.c \
		stack_operations_4.c \
		stack_operations_5.c \
		stack_operations_6 \
		sorting_2.c

SRC_CH = checker.c \
		stack_operations.c \
		stack_operations_3.c \
		stack_operattons_2.c \
		stack_operations_both.c \
		reading.c \
		stack_operations_4.c \
		stack_operations_5.c \
        stack_operations_6

OBJ_PS = $(SRC_PS:.c=.o)

OBJ_CH = $(SRC_CH:.c=.o)

HEADER = push_swap.h

CC = gcc

CFLAGS = -c

all: $(NAME_PS) $(NAME_CH)

$(NAME_PS): $(OBJ_PS)
		@cd libft && $(MAKE)
		@gcc -o $(NAME_PS) $(OBJ_PS) $(LIBFT)
		@echo "Executive $(NAME_PS) has been compiled (all rule)."

$(NAME_CH): $(OBJ_CH)
		@cd libft && $(MAKE)
		@gcc -o $(NAME_CH) $(OBJ_CH) $(LIBFT)
		@echo "Executive $(NAME_CH) has been compiled (all rule)."

%.o: %.c $(HEADER)
		@$(CC) $(CFLAGS) -o $@ $<

clean:
		@rm -f $(OBJ_PS) $(OBJ_CH)
		@echo "Object files of $(NAME_PS) and $(NAME_CH) has been deleted (clean rule)."
		@cd libft && $(MAKE) clean

fclean: clean
		@rm -f $(NAME_PS) $(NAME_CH)
		@echo "Executives $(NAME_PS) and $(NAME_CH) has been deleted (fclean rule)."
		@cd libft && $(MAKE) fclean

re: lib_recompile $(OBJ_PS) $(OBJ_CH)
		@rm -f $(OBJ)
		@echo "Object files of $(NAME_PS) and $(NAME_CH) has been deleted (clean rule)."
		@rm -f $(NAME)
		@echo "Executives $(NAME_PS) and $(NAME_CH) has been deleted (fclean rule)."
		@gcc -o $(NAME_PS) $(OBJ_PS) $(LIBFT)
		@echo "Executive $(NAME_PS) has been compiled (all rule)."
		@gcc -o $(NAME_CH) $(OBJ_CH) $(LIBFT)
		@echo "Executive $(NAME_CH) has been compiled (all rule)."

lib_recompile:
		@cd libft && $(MAKE) re
		@echo "Library has been recompiled (re rule)."
