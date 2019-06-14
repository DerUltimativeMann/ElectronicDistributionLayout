# ElectronicDistributionLayout EDL
PROG = EDL

# Compiler GNU-C
CC = gcc

# Compiler flags
CF = -Wall -pedantic -ansi

# Library flags
LF = -lgdi32

# .o files
OBJ = main.o windowprocs.o

# Binding the program
$(PROG): $(OBJ)
	$(CC) -o $(PROG) $(OBJ) $(LF)
	rm $(OBJ)

# Compile the code
%.o: %.c
	$(CC) -c $(CF) $<
