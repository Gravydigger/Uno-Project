OBJ = Deck.o Card.o Player.o GameManager.o ActionCard.o Draw2.o WildCard.o StandardCard.o

CC = clang++

run: UnoFinal
	./UnoFinal

UnoFinal: $(OBJ) UnoFinalMain.cpp
	$(CC) $(OBJ) UnoFinalMain.cpp -o UnoFinal

Player.o: Player.cpp
	$(CC) -c Player.cpp

Card.o: Card.cpp
	$(CC) -c Card.cpp

StandardCard.o: StandardCard.cpp
	$(CC) -c StandardCard.cpp

Deck.o: Deck.cpp
	$(CC) -c Deck.cpp

GameManager.o: GameManager.cpp
	$(CC) -c GameManager.cpp
	
ActionCard.o: ActionCard.cpp
	$(CC) -c ActionCard.cpp

Draw2: Draw2.ccp ActionCard.cpp
	$(CC) -c Draw2.cpp ActionCard.cpp
	
WildCard: WildCard.ccp ActionCard.cpp
	$(CC) -c WildCard.cpp ActionCard.cpp
	
UnitTest: $(OBJ) UnitTestingMain.cpp
	$(CC) $(OBJ) UnitTestingMain.cpp -o UnitTest

runUnitTest1: UnitTest
	./UnitTest < input01.txt | diff - output01.txt

runUnitTest2: UnitTest
	./UnitTest < input02.txt | diff - output02.txt