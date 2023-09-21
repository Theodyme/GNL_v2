CC = gcc
CFLAGS = -Wall -Wextra -D BUFFER_SIZE=10  # Replace n with the desired BUFFER_SIZE

SRC = get_next_line.c get_next_line_utils.c main.c
OBJ = $(SRC:.c=.o)

EXE = gnl

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(EXE) $(OBJ)
