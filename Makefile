CC = gcc
CFLAGS = -Wall -Iinclude
SRC = src/data/data_types/strings.c src/expiration/ttl.c src/server.c src/main.c
OBJ = $(SRC:.c=.o)
TARGET = build/myredis

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(TARGET)

run-server:
	./build/myredis

run-client:
	nc localhost 6379