CC = gcc
CFLAGS = -Wall -Iinclude
SRC = src/data/data_types/strings.c src/expiration/ttl.c
OBJ = $(SRC:.c=.o)
TARGET = build/myredis

$(TARGET): $(OBJ)
    $(CC) $(CFLAGS) -o $@ $^
