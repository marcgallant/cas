CC = gcc
CFLAGS = -fPIC -Wall -Wextra -Werror -std=c11 -g -I utils

SRC = utils/hash_map/hash.c \
      utils/hash_map/hash_map.c \
      utils/dlist/dlist.c \
      utils/arg_parser/arg_parser.c \
      cJSON.c \
      configschema.c \
      plugins/plugins.c \
      plugins/clean.c \
      cas.c
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

