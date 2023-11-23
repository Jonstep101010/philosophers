NAME		  := philo_bonus
.DEFAULT_GOAL := all

# --------------------------------- includes --------------------------------- #

INCS		= ./include

BUILD_DIR	:= .build

# ---------------------------------------------------------------------------- #
#                                 source files                                 #
# ---------------------------------------------------------------------------- #

VPATH		:= src/

SRC			:= main.c user_input.c utils_mem.c utils_time.c setup.c \
				philo_actions.c printing.c routine.c deconstruct.c \
				sim.c utils_to.c forked_process.c

SRCS		:= $(SRC)

# ---------------------------------------------------------------------------- #
#                             compilation arguments                            #
# ---------------------------------------------------------------------------- #

OBJS		:= $(addprefix $(BUILD_DIR)/, $(SRCS:%.c=%.o))
DEPS		:= $(OBJS:.o=.d)

CC			:= clang
CFLAGS		?= -g3 -Wall -Wextra -Werror -pthread -fsanitize=thread #-Wpedantic
CPPFLAGS	:= $(addprefix -I,$(INCS)) -MMD -MP

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

update: fclean
	git stash
	git pull
	git stash pop

run: all
	./$(NAME) 4 300 200 200 

memcheck: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) 50 1001 400 450

debug: all#--log-file=valgrind.log  
	valgrind --tool=helgrind --trace-children=yes \
	./$(NAME) 4 300 200 200

.PHONY: run update re
# .SILENT:
-include $(DEPS)
