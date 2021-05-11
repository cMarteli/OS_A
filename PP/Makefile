## ================================== ##
#   File: Makefile                     #
#   File Created: --                   #
#   Author: Caio Marteli               #
#                                      #
## ================================== ##


# Makefile Variables
CC		 = gcc
EXEC	 = PP
CFLAGS = -Wall #-ansi -pedantic
LFLAGS = # -lpthread
OBJ 	 = main.o fileIO.o schedulers.o priorityQueue.o#Change

# Add FANCY to the CFLAGS and recompile the program
ifdef FANCY 
CFLAGS += -D FANCY
FANCY : clean $(EXEC)
endif

# Add DEBUG to the CFLAGS and recompile the program
ifdef DEBUG
CFLAGS += -D DEBUG
DEBUG : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(LFLAGS)

main.o : main.c #change and add classes
fileIO.o : fileIO.c
schedulers.o : schedulers.c
priorityQueue.o : priorityQueue.c
	$(CC) $(CFLAGS) main.c -c
	$(CC) $(CFLAGS) fileIO.c -c
	$(CC) $(CFLAGS) schedulers.c -c
	$(CC) $(CFLAGS) priorityQueue.c -c

clean:
	rm -f $(EXEC) $(OBJ)