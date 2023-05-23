CC = g++

EXE = main.exe

SRC = $(wildcard *.cc)

OBJ = $(patsubst %.cc,%.o,$(SRC))

FLG = -Wall -g #-O2 

$(EXE):$(OBJ)
	clear
	$(CC) -o $@ $^ $(FLG)
	

$(OBJ):%.o:%.cc
	$(CC) -o $@ -c $< $(FLG)

clean:
	@rm -rf $(EXE) $(OBJ)

run:
	@./$(EXE)

plot:
	gnuplot grafico.gp
