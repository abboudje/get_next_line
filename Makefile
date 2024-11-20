# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)
NAME = libgnl.a
TEST_SRC = main.c
TEST = test

# Targets
all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJ)

# Remove the library and object files
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Test the get_next_line function
test: $(OBJ) $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) $(OBJ) -o $(TEST)

# Run the test
run_test: test
	./$(TEST)

