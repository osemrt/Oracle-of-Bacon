TARGET = main

SRC = src
INC = inc
BIN = bin

SOURCE = $(wildcard $(SRC)/*.c)
OBJECT = $(patsubst %,$(BIN)/%, $(notdir $(SOURCE:.c=.o)))

CC = gcc
CFLAGS = -Wall -std=gnu99 -I$(/INC)

RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
YELLOW = \033[1;33m
NC = \033[1;0m

$(BIN)/$(TARGET) : $(OBJECT)
	@echo "$(GREEN)Linking...$(NC)"
	$(CC) -o $@ $^

$(BIN)/%.o : $(SRC)/%.c
	@echo "$(RED)Compiling..$(NC)"
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)Finished!$(NC)"

.PHONY : help run clean

run : $(BIN)/$(TARGET)
	@echo "$(YELLOW)Running...$(NC)"
	$(BIN)/$(TARGET)

clean:
	rm -f $(OBJECT)	 $(BIN)/$(TARGET)

help:
	@echo "src: $(SOURCE)"
	@echo "obj: $(OBJECT)"
