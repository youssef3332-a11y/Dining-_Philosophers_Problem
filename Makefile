# Variables
CC = gcc
CFLAGS = -Wall -g
TARGET = dining_table


all: $(TARGET)


$(TARGET): main.o
	@$(CC) $(CFLAGS) -o $(TARGET) main.o


main.o: main.c headerfile.h
	@if ! dpkg -l | grep -q libc6-dev ;then \
	echo "installing the pthread library"; \
	sudo apt update && sudo apt install libc6-dev; \
	else \
	echo "all packages are installed"; \
	fi
	@echo "le program is linking"
	@echo "le program est en cours d'execution"
	@$(CC) $(CFLAGS) -c main.c


clean:
	@echo "all the files created will be deleted not uncluding the source code"
	@rm -f $(TARGET) *.o
