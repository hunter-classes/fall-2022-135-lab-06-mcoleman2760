main: main.o funcs.o caesar.o vigenere.o decrypt.o
	g++ -o main main.o funcs.o caesar.o vigenere.o decrypt.o

tests: tests.o funcs.o caesar.o vigenere.o decrypt.o
	g++ -o tests tests.o funcs.o caesar.o vigenere.o decrypt.o



funcs.o: funcs.cpp funcs.h

main.o: main.cpp funcs.h

tests.o: tests.cpp doctest.h funcs.h

test-ascii.o: test-ascii.cpp

caesar.o: caesar.cpp caesar.h

vigenere.o: vigenere.cpp vigenere.h

decrypt.o: decrypt.cpp decrypt.h

clean:
	rm -f main.o funcs.o tests.o  test-ascii.o caesar.o vigenere.o decrypt.o
