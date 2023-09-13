# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/31 17:32:13 by sadoming          #+#    #+#              #
#    Updated: 2023/09/13 16:03:46 by sadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnextline.a
TEST = test.out
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=10

# Sources:
MAK = Makefile
LIB = get_next_line.h get_next_line_bonus.c
TLIB = test_getnextline.h

SRC = get_next_line.c get_next_line_utils.c
BNS = get_next_line_bonus.c get_next_line_utils_bonus.c

TSRC = test_getnextline_main.c test_utils.c $(SRC)
TSRB = test_getnextline_main.c test_utils.c $(BNS)

OBJ = $(patsubst %.c, %.o, $(SRC))
OBJB = $(patsubst %.c, %.o, $(BNS))
TOBJ = $(patsubst %.c, %.o, $(TSRC)) $(LIB)
#------------------------------------------------------------------------------#

all: $(TEST)

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
	@norminette $(BNS)
	@echo "\033[0;37m\n"
	@gcc $(CFLAGS) -D TBNS=0 -o $(TEST) *.o
	@echo * "\n"

# ./test.out:
test: $(TEST)
	@leaks -atExit -- ./$(TEST)
	@/bin/rm -f *.o

# ******************************************************************************* #
# lldb:
DEB = debug.out
DEBB = $(SRC) $(TSRC)

$(DEB): $(DEBB)
	@gcc -g $(CFLAGS) -o $(DEB) $(DEBB)

debug: $(DEB)
	@lldb $(DEB)

valgrind: $(DEB)
	@gcc -g $(FLAGS) -o $(DEB) $(DEBB)
	@valgrind ./$(DEB)

# ********************************************************************************* #
clean:
	@/bin/rm -f *.o
	@/bin/rm -f $(TEST)
	@/bin/rm -f $(TBO)
	@/bin/rm -f $(DEB)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -frd test.out.dSYM
	@/bin/rm -frd debug.out.dSYM
	@/bin/rm -f .DS_Store

clear: fclean
	@clear
# -------------------- #
.PHONY: all clean clear fclean debug test valgrind

# ********************************************************************************** #
