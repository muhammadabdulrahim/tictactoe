CC		:= gcc
CFLAGS	:= -Wall
SRCS	:= $(wildcard *.c)
OBJS	:= $(SRCS:.c=.o)
TARGET	:= tictactoe.a

default: all

all: $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm $(OBJS) $(TARGET)

run:
	./$(TARGET)