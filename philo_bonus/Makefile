NAME		  := philo_bonus
.DEFAULT_GOAL := all

# --------------------------------- includes --------------------------------- #

INCS		= ./include

BUILD_DIR	:= .build

# ---------------------------------------------------------------------------- #
#                                 source files                                 #
# ---------------------------------------------------------------------------- #

VPATH		:= src/ src/utils src/philos src/sim
SRC			:= main.c 

SRC_UTILS	:= user_input.c ft_calloc.c utils_time.c deconstruct.c \
				ft_atol.c ft_itoa.c ft_strjoin.c
SRC_PHILO	:= forked_process.c threads.c routine.c philo_utils.c
SRC_SIM		:= sim.c setup.c
SRCS		:= $(SRC) $(SRC_UTILS) $(SRC_PHILO) $(SRC_SIM)

# ---------------------------------------------------------------------------- #
#                             compilation arguments                            #
# ---------------------------------------------------------------------------- #

OBJS		:= $(addprefix $(BUILD_DIR)/, $(SRCS:%.c=%.o))
DEPS		:= $(OBJS:.o=.d)

CC			:= clang
CFLAGS		?= -g3 -Wall -Wextra -Werror -pthread #-fsanitize=thread -O1#-Wpedantic
CPPFLAGS	:= $(addprefix -I,$(INCS)) -MMD -MP

MAKEFLAGS	+= --no-print-directory --silent

ifeq ($(uname -s),Darwin)
DONE		= printf "\033[0;32m\xE2\x9C\x93\033[0m "
DONE_NL		= printf "\033[0;32m\xE2\x9C\x93\n\033[0m"
else
DONE		= printf "\033[0;32m✓\033[0m "
DONE_NL		= printf "\033[0;32m✓\033[0m\n\n"
endif

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

memcheck: all# 
	valgrind --tool=memcheck --leak-check=full ./$(NAME) 4 300 200 200

debug: all#--log-file=valgrind.log   
	valgrind --tool=drd --trace-children=yes --trace-semaphore=yes -s --log-file=valgrind.log ./$(NAME) 5 500 200 200

.PHONY: run update re
# .SILENT:
-include $(DEPS)
