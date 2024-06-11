# Variables
CC = gcc
CFLAGS = -Wall -g
TARGET = dining_table


all: $(TARGET)


$(TARGET): main.o
	@echo "le program is linking"
	$(CC) $(CFLAGS) -o $(TARGET) main.o


main.o: main.c headerfile.h
	@echo "le program est aucours d'execution"
	$(CC) $(CFLAGS) -c main.c


clean:
	@echo "all the files created will be deleted not uncluding the source code"
	rm -f $(TARGET) *.o