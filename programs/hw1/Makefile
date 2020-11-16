# paths
INCLUDE = ../../include
MODULES=../../modules

# compiler
CC = g++ 

# Compile options. Το -I<dir> λέει στον compiler να αναζητήσει εκεί include files
CPPFLAGS = -Wall  -g -I$(INCLUDE)
LDFLAGS = -lm

# Αρχεία .o
OBJS = $(MODULES)/student.o $(MODULES)/infrastructures.o  main.o 

# Το εκτελέσιμο πρόγραμμα
EXEC = main

ARGS= 1 5 17 10



$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)


clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC) $(ARGS)

valgrind: run
	valgrind ./$(EXEC)