gettagnew.out: bodyelement.o docparse.o function.o gettagnew.o headelement.o function.o
		gcc -o gettagnew.out bodyelement.o docparse.o function.o gettagnew.o headelement.o

bodyelement.o: bodyelement.c element.h variable.h
	gcc -c -o bodyelement.o bodyelement.c

headelement.o: headelement.c element.h variable.h
	gcc -c -o headelement.o headelement.c

docparse.o: docparse.c element.h variable.h
	gcc -c -o docparse.o docparse.c

function.o: function.c function.h variable.h
	gcc -c -o function.o function.c

gettagnew.o: gettagnew.c variable.h
	gcc -c -o gettagnew.o gettagnew.c