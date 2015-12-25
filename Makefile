# Hashes start line comments in Makefiles.

# Here we define a few variables that we use later.
NAME=repl
TESTS=tests
CC=gcc

# These are various C compiler flags.
CFLAGS=-Wall -lrt -lm #-DNDEBUG
# Flags:
#  -Wall enable all warnings
#  -lrt  timing library
#  -lm   math library
#  -DNDEBUG disables debugging, uncomment if needed above

# `make`
# When calling `make`, the first argument we pass determines what happens
# next. The default (`make`) just matches the first event, `all`, defined
# below. All it does is call the `compile` event, so `make` is the same
# as `make compile` followed by `make run`
all: compile

repl: compile
	valgrind --track-origins=yes ./$(NAME)

# `make compile`
# Notice we can use variables with the $(VAR_NAME) syntax.
# We insert the compiler flags and the name of the C compiler via variables.
compile:
	$(CC) repl.c core.c util.c -o $(NAME) $(CFLAGS)

# `make clean`
# Deletes the file called NAME (defined above).
clean:
	rm $(NAME)

# `make test`
# Compile and run the test suite under Valgrind.
test:
	$(CC) core.c util.c tests.c -o $(TESTS) $(CFLAGS)
	valgrind --track-origins=yes ./$(TESTS)
