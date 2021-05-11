## ================================== ##
#   File: Makefile                     #
#   File Created: --                   #
#   Author: Caio Marteli               #
#                                      #
## ================================== ##


# Makefile Variables
CC		 = gcc
EXEC	 = ThreadProgram
CCFLAGS = -Wall
LFLAGS = -lpthread
OBJ 	 = parentThread.o

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

parentThread.o : parentThread.c #change and add classes
	$(CC) $(CCFLAGS) parentThread.c -c

clean:
	rm -f $(EXEC) $(OBJ)