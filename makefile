CC		:= gcc
CFLAGS	:= -Wall
SRCS	:= tictactoe.c
OBJS	:= ${SRCS:.c=.o}
TARGET	:= ${SRCS:.c=.a}

default: all

all: $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

run:
	./$(TARGET)