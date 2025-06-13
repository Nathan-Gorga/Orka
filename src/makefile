

orka: orka.o fetch.o cli.o
	gcc orka.o fetch.o cli.o -o orka
	make clean
	./orka.exe

orka.o: orka.c
	gcc -c orka.c -o orka.o

fetch.o: ./fetch/codebase_location.c
	gcc -c ./fetch/codebase_location.c -o fetch.o

cli.o : ./cli/cli.c
	gcc -c ./cli/cli.c -o cli.o	


clean:
	del *.o

