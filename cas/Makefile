CC = gcc
CFLAGS = -fPIC -Wall -Wextra -Werror -std=c11 -I include -g
LDFLAGS = -L/usr/local/lib
LDLIBS = -lcjson

SRC = configschema.c cas.c
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

