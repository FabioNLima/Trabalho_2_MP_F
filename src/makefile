IDIR =../include
CXX=g++
CXXFLAGS=-I$(IDIR) -g

ODIR= ./obj

LIBS= -lncurses -lgtest -lpthread -lgtest_main
LIBS_C = -ftest-coverage -fprofile-arcs

_DEPS = romanos.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = romanos.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cc $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(LIBS)

main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o Gerenciador TelaInicial.cpp $(OBJ) $(LIBS)

.PHONY: teste

teste: $(OBJ)
	$(CXX) -o teste test_romanos.cc $(OBJ) $(CXXFLAGS) $(LIBS) $(LIBS_C)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~ 
