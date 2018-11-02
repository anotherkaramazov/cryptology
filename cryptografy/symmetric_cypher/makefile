IDIR=include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR=lib
SRC=src
BIN=bin

LIBS=-lm

_DEPS = symmetric_cypher.h substitution_cypher.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = symmetric_cypher.o substitution_cypher.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SRC)/%.c $(DEPS)
	$(CC) -c -g -o $@ $< $(CFLAGS)

symmetric_cypher: $(OBJ)
	$(CC) -g -o $(BIN)/$@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(BIN)/*~ core $(INCDIR)/*~ 
