CC = g++

SRC = $(wildcard *.cc)

OBJ = $(patsubst %.cc,%.o,$(SRC))

FLG = -Wall -g -O2 



$(SRC):
	$(CC) -o $@ $^ $(FLG)

$(OBJ):%.o:%.cc
	$(CC) -o $@ -c $< $(FLG)

clean:
	@rm -rf $(EXE) $(OBJ)

run:
	@./$(EXE)

