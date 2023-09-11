# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/31 17:32:13 by sadoming          #+#    #+#              #
#    Updated: 2023/09/11 20:17:47 by sadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnextline.a
TEST = test.out
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=9999

# Sources:
MAK = Makefile
LIB = get_next_line.h get_next_line_bonus.c
TLIB = test_getnextline.h

SRC = get_next_line.c get_next_line_utils.c
BNS = get_next_line_bonus.c get_next_line_utils_bonus.c
TSRC = test_getnextline_main.c test_utils.c

OBJ = $(patsubst %.c, %.o, $(SRC))
OBJB = $(patsubst %.c, %.o, $(BNS))
TOBJ = $(patsubst %.c, %.o, $(TSRC)) $(TLIB)
#------------------------------------------------------------------------------#

all: $(NAME)

%.o : %.c $(MAK) $(LIB)
	@gcc $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

bonus: $(OBJB)
	ar rc $(NAME) $(OBJB)

# make test.out:
$(TEST): $(OBJ) $(TOBJ) 
	@echo "\n\033[1;93m~ Norminette:"
	@norminette $(SRC)
	@echo "\033[0;37m\n"
	@gcc $(CFLAGS) -o $(TEST) *.o
	@echo * "\n"

# ./test.out:
test: $(TEST)
	@valgrind ./$(TEST)

# ******************************************************************************* #
# lldb:
DEB = debug.out
DEBB = $(SRC) $(TSRC)

$(DEB): $(DEBB)
	@gcc -g $(CFLAGS) -o $(DEB) $(DEBB)

debug: $(DEB)
	@lldb $(DEB)

# ********************************************************************************* #
clean:
	@/bin/rm -f *.o
	@/bin/rm -f $(TEST)
	@/bin/rm -f $(DEB)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -frd test.out.dSYM
	@/bin/rm -frd debug.out.dSYM

clear: fclean
	@clear
# -------------------- #
.PHONY: all clean clear fclean debug test

# ********************************************************************************** #
