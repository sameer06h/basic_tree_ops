#declare variable 
CC := gcc
CFLAGS := -Wall
TARGET := bst_operations

all: $(TARGET) 

$(TARGET): bst_operations.o 
	$(CC) $(CFLAGS) bst_operations.o -o bst_operations

bst_operations.o: bst_operations.c tree_api.o 
	$(CC) $(CFLAGS) -c bst_operations.c -o bst_operations.o 

tree_api.o: tree_api.h def.h common_utils.h 
	$(CC) $(CFLAGS) tree_api.h -o tree_api.o

clean:
	rm -rf *o bst_operations
