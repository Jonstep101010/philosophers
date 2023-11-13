NAME		  := philo
.DEFAULT_GOAL := all

# --------------------------------- includes --------------------------------- #

INCS		= ./include \
				./include/io \
				./include/setup \
				./include/utils \
				./include/philosim

BUILD_DIR	:= .build

# ---------------------------------------------------------------------------- #
#                                 source files                                 #
# ---------------------------------------------------------------------------- #

VPATH		:= src/ src/io src/setup src/utils src/philosim

SRC			:= main.c
SRC_IO		:= parse_input.c ft_atol.c
SRC_SETUP	:= set_philos.c
SRC_UTILS	:= ft_calloc.c checks.c cleanup.c time.c
SRC_SIM		:= sim.c printing.c routine.c

SRCS		:= $(SRC) $(SRC_IO) $(SRC_SETUP) $(SRC_UTILS) $(SRC_SIM)

# ---------------------------------------------------------------------------- #
#                             compilation arguments                            #
# ---------------------------------------------------------------------------- #

OBJS		:= $(addprefix $(BUILD_DIR)/, $(SRCS:%.c=%.o))
DEPS		:= $(OBJS:.o=.d)

CC			:= clang
CFLAGS		?= -g3 -Wall -Wextra -Werror -pthread #-Wpedantic
# DBGFLAGS	?=
CPPFLAGS	:= $(addprefix -I,$(INCS)) -MMD -MP
# LDFLAGS		= $(addprefix -L, $(dir $(LIB_FT)))
# LDLIB		:= $(addprefix -l, "pthreads")

MAKEFLAGS	+= --no-print-directory #--silent

DONE		= printf "\033[0;32m\xE2\x9C\x93\033[0m "
DONE_NL		= printf "\033[0;32m\xE2\x9C\x93\n\033[0m"

# ---------------------------------------------------------------------------- #
#                             building the program                             #
# ---------------------------------------------------------------------------- #

all: $(NAME)

$(NAME): $(OBJS)
	$(info creating $(NAME) executable)
	$(CC) $(CFLAGS) $(OBJS) $(CPPFLAGS) -o $(NAME)
	$(DONE_NL)

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $< && $(DONE)
	echo $(notdir $<)
# info $($<)
$(BUILD_DIR):
	mkdir -p .build

# ---------------------------------------------------------------------------- #
#                                     rules                                    #
# ---------------------------------------------------------------------------- #

clean:
	$(info Cleaning...)
	rm -rf .build
	$(DONE_NL)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

# ----------------------------- additional rules ----------------------------- #
# git submodule update --init --recursive
INPUT	= 2 800 200 200

update: fclean
	git stash
	git pull
	git stash pop

run: all
	./$(NAME) 2 800 200 200 

norme:
	clear
	-norminette src/ | grep Error

memcheck: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(INPUT)

debug: all
	valgrind --tool=helgrind --check-stack-refs=yes --track-lockorders=yes \
	./$(NAME) 2 800 200 200

# test:
# 	cd ./../tests-pipex && sh ./test.sh

.PHONY: run update re
# .SILENT:
-include $(DEPS)
