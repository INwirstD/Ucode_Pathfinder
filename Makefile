CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

NAME = pathfinder

INC = inc
OBJ = obj
SRC = src
LIBD = libmx
LIB = $(LIBD)/libmx.a

RM := rm -rf
SRCS := $(wildcard $(SRC)/*.c)
OBJS := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

.PHONY: all install clean uninstall reinstall

all: install

install: $(LIB) $(NAME)

$(LIB):
	@make -C $(LIBD)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -I$(INC) $^ $(LIB) -o $@
	@echo "[$(NAME)] created successfully."

$(OBJS): $(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -I$(LIBD)/$(INC) -c $< -o $@
	@echo "[$(NAME)] compiled: $<"

$(OBJ):
	@mkdir -p $(OBJ)

uninstall: clean
	@make -C $(LIBD) uninstall
	@$(RM) $(NAME)
	@echo "[$(NAME)] uninstalled."

clean:
	@make -C $(LIBD) clean
	@$(RM) $(OBJ)
	@echo "[$(NAME)] cleaned."

reinstall: uninstall all



