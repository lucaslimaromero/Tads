APPS =./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src

all: libed myapps

libed:
	gcc -c $(SRC)/NOME_DO_TAD.c -I $(INCLUDE) -o $(OBJ)/NOME_DO_TAD.o

myapps:
	gcc $(APPS)/NOME_DO_APP.c $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/NOME_DO_APP

run:
	$(BIN)/NOME_DO_APP

clean:
	rm $(BIN)/* $(OBJ)/*