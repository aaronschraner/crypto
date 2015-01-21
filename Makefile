CC=g++
winCC=x86_64-w64-mingw32-g++
winCFLAGS=-static
CFLAGS=-Wall
A=crypto
OBJECTS=caesar.o substitution.o vigenere.o transposition.o

default: $(OBJECTS) $(A)

build: $(OBJECTS) $(A)

$(A): $(A).cpp
	$(CC) -o $(A) $(A).cpp $(CFLAGS) $(OBJECTS)

windows:
	$(winCC) -o $(A).exe algorithms/*.cpp $(A).cpp $(winCFLAGS)

run: $(OBJECTS) $(A) 
	./$(A)

caesar.o: algorithms/caesar.cpp
	$(CC) -c algorithms/caesar.cpp $(CFLAGS) -o caesar.o

substitution.o: algorithms/substitution.cpp
	$(CC) -c algorithms/substitution.cpp $(CFLAGS) -o substitution.o

vigenere.o: algorithms/vigenere.cpp
	$(CC) -c algorithms/vigenere.cpp $(CFLAGS) -o vigenere.o

transposition.o: algorithms/transposition.cpp
	$(CC) -c algorithms/transposition.cpp $(CFLAGS) -o transposition.o

hacky:
	$(CC) $(FLAGS) $(A).cpp algorithms/*.cpp -o $(A)_hacky

clean:
	rm -fv crypto *.o *~ algorithms/*~ *.exe crypto_hacky

tidy:
	rm -fv algorithms/*~
