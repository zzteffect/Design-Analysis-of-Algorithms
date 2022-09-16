#$> program1 –m <market-price-file> -p <price-list-file>
COURSE = cs375
SEMESTER = fall2022
CP_NUMBER = 1
LASTNAME = Zhou
FIRSTINITIAL = Z
EXE = program1

REPODIR = $(COURSE)-p$(CP_NUMBER)
TARFILE = $(LASTNAME)_$(FIRSTINITIAL)_p$(CP_NUMBER).tar

FLAGS = -g -O3
CC = g++
BIN = bin
OBJ = obj

# Store executables in a subdirectory
all: $(BIN)/$(EXE)

$(BIN)/$(EXE): main.o Help.o Collection.o Card.o
	$(CC) $(FLAGS) main.o Help.o Collection.o Card.o -o $@

# OBJECTS BELOW
$(OBJ)/main.o: main.cpp Help.h Parser.h 
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ)/Help.o: Help.cpp Help.h Parser.h Collection.h
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ)/Collection.o: Collection.cpp Card.h
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ)/Card.o: Card.cpp Card.h
	$(CC) $(FLAGS) -c $< -o $@

# Run make tar to build a .tar.gz file appropriate for uploading to Brightspace
#tar -czf archive-name.tar.gz file-name...
tar:	clean
#tar cvvf $(TARFILE) $(REPODIR)
	tar -czf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)

clean:
	rm -f $(OBJ)/*.o $(BIN)/$(EXE) *.tar.gz
	rm -f *.o 