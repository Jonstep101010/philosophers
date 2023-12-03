NAME		  := philo
.DEFAULT_GOAL := all

# --------------------------------- includes --------------------------------- #

INCS		= ./include \
				./include/sim \
				./include/utils \
				./include/philos

BUILD_DIR	:= .build

# ---------------------------------------------------------------------------- #
#                                 source files                                 #
# ---------------------------------------------------------------------------- #

VPATH		:= src/ src/philos src/sim src/utils

SRC			:= main.c
SRC_PHILO	:= routine.c philo_utils.c
SRC_SIM		:= setup.c sim.c
SRC_UTILS	:= ft_calloc.c checks.c deconstruct.c utils_time.c user_input.c ft_atol.c

SRCS		:= $(SRC) $(SRC_PHILO) $(SRC_SIM) $(SRC_UTILS)

# ---------------------------------------------------------------------------- #
#                             compilation arguments                            #
# ---------------------------------------------------------------------------- #

OBJS		:= $(addprefix $(BUILD_DIR)/, $(SRCS:%.c=%.o))
DEPS		:= $(OBJS:.o=.d)

CC			:= clang
CFLAGS		?= -g3 -Wall -Wextra -Werror -pthread #-fsanitize=thread#-Wpedantic
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

run: all
	./$(NAME) 4 300 200 200 

norme:
	clear
	-norminette src/ | grep Error

memcheck: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) 4 1001 400 450 3

debug: all#--log-file=valgrind.log  
	valgrind --tool=helgrind ./$(NAME) 3 80000 200 200

.PHONY: run update re
# .SILENT:
-include $(DEPS)
