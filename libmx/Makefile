CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic


INC = $(wildcard inc/*.h)
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))

MKDIR := mkdir -p
RM := rm -rf

LIB_NAME = libmx.a

.PHONY: all clean uninstall reinstall

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
	@ar rcs $@ $^
	@echo "[$(LIB_NAME)] created successfully."

obj/%.o: src/%.c $(INC) | obj
	@$(CC) $(CFLAGS) $(INC_DIR) -o $@ -c $< -I inc
	@echo "[$(LIB_NAME)] compiled: $<"

obj:
	@$(MKDIR) $@

clean:
	@$(RM) obj
	@echo "[$(LIB_NAME)] cleaned."

uninstall: clean
	@$(RM) $(LIB_NAME)
	@echo "[$(LIB_NAME)] uninstalled."

reinstall: uninstall all
