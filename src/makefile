

orka: orka.o fetch.o parseCLI.o flagCallFunctions.o
	gcc orka.o fetch.o parseCLI.o flagCallFunctions.o -o orka
	make clean
	./orka.exe

orka.o: orka.c
	gcc -c orka.c -o orka.o

fetch.o: ./fetch/codebase_location.c
	gcc -c ./fetch/codebase_location.c -o fetch.o

parseCLI.o : ./cli/parseCLI.c 
	gcc -c ./cli/parseCLI.c -o parseCLI.o	

flagCallFunctions.o : ./cli/flagCallFunctions.c 
	gcc -c ./cli/flagCallFunctions.c -o flagCallFunctions.o

clean:
	del *.o

