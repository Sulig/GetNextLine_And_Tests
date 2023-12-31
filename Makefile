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

TEST = test.out
DIR = ./GetNextLine/
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=10

# Sources:
MAK = Makefile
LIB = $(DIR)get_next_line.h $(DIR)get_next_line_bonus.c
TLIB = Tests/test_getnextline.h

SRC = $(DIR)get_next_line.c $(DIR)get_next_line_utils.c
BNS = $(DIR)get_next_line_bonus.c $(DIR)get_next_line_utils_bonus.c

TSRC = Tests/test_getnextline_main.c Tests/test_utils.c $(SRC)

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
	@gcc $(CFLAGS) -o $(TEST) $(DIR)*.o Tests/*.o
	@echo * "\n"

# ./test.out:
test: $(TEST)
	@leaks -atExit -- ./$(TEST)
	@/bin/rm -f $(DIR)*.o

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
	@/bin/rm -f Tests/*.o
	@/bin/rm -f $(TEST)
	@/bin/rm -f $(DEB)

fclean: clean
	@/bin/rm -frd test.out.dSYM
	@/bin/rm -frd debug.out.dSYM
	@/bin/rm -f .DS_Store

clear: fclean
	@clear
# -------------------- #
.PHONY: all clean clear fclean debug test valgrind

# ********************************************************************************** #
