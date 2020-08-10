main.out: bodyelement.o docparse.o function.o main.o headelement.o function.o createDom.o
		gcc -o main.out bodyelement.o docparse.o function.o main.o headelement.o createDom.o

bodyelement.o: bodyelement.c element.h variable.h
	gcc -c -o bodyelement.o bodyelement.c

headelement.o: headelement.c element.h variable.h
	gcc -c -o headelement.o headelement.c

docparse.o: docparse.c element.h variable.h
	gcc -c -o docparse.o docparse.c

function.o: function.c function.h variable.h
	gcc -c -o function.o function.c

main.o: main.c variable.h
	gcc -c -o main.o main.c

createDom.o: createDom.c domVariable.h
	gcc -c -o createDom.o createDom.c