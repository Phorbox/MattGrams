cardBattler: main.o cardBattle.o
	gcc main.o cardBattle.o -o cardBattler
main.o: main.c cardBattle.h
	gcc -c main.c
cardBattle.o: cardBattle.c cardBattle.h
	gcc -c cardBattle.c
clean:
	rm *.o cardBattler
