CC = gcc
CFLAGS = -fPIC -Wall -Wextra -Werror -std=c11 -I include -g

SRC = cJSON.c configschema.c cas.c
OBJ = $(SRC:.c=.o)
BIN = cas

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(BIN)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(BIN) $(OBJ)

.PHONY : all clean

