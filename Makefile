main.out: bodyelement.c createDom.c docparse.c function.c headelement.c main.c 
	gcc -o main.out -g bodyelement.c createDom.c docparse.c function.c headelement.c main.c

