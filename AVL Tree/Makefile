APPS =./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src

all: libed myapps

libed:
	gcc -c $(SRC)/avl_tree.c -I $(INCLUDE) -o $(OBJ)/avl_tree.o

myapps:
	gcc $(APPS)/app.c $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/app

run:
	$(BIN)/app

clean:
	rm $(BIN)/* $(OBJ)/*