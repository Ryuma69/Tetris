CC=gcc
option1= -g -W -Wall -pedantic -std=c89 -O3
option2=`pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV`
option3=`pkg-config --libs-only-l MLV`
option4= -Iinclude

all : tetris clean

tetris: structure.o main.o matrice.o affichage.o save.o 
	$(CC) $(option1) $(option2) $(option4) matrice.o structure.o main.o affichage.o save.o $(option3) -o tetris

main.o: source/main.c
	$(CC) $(option1) $(option4) -c $^ # le $^ Fait ref à source/main.c

structure.o: source/structure.c
	$(CC) $(option1) $(option4) -c $^

matrice.o: source/matrice.c
	$(CC) $(option1) $(option4) -c $^

affichage.o: source/affichage.c
	$(CC) $(option1) $(option4) -c $^

save.o: source/save.c
	$(CC) $(option1) $(option4) -c $^




clean:
	rm -r *.o 
clean_exe:
	rm -rf *.o tetris
