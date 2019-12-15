

output: Main.o DoublyLinkedList.o Space.o GamePlay.o Character.o Bear.o Bandit.o Wolf.o InputValidation.o Player.o Merchant.o Die.o Object.o Water.o Lumber.o Hammer.o Nails.o Axe.o Observation.o Board.o
	g++ -std=c++11 Main.o DoublyLinkedList.o Space.o GamePlay.o Character.o Bear.o Bandit.o Wolf.o InputValidation.o Player.o Merchant.o Die.o Object.o Water.o Lumber.o Hammer.o Nails.o Axe.o Observation.o Board.o -o output

Main.o: Main.cpp
	g++ -std=c++11 -c Main.cpp

DoublyLinkedList.o: DoublyLinkedList.cpp
	g++ -std=c++11 -c DoublyLinkedList.cpp

Space.o: Space.cpp
	g++ -std=c++11 -c Space.cpp

GamePlay.o: GamePlay.cpp
	g++ -std=c++11 -c GamePlay.cpp

Character.o: Character.cpp
	g++ -std=c++11 -c Character.cpp

Bear.o: Bear.cpp
	g++ -std=c++11 -c Bear.cpp

Bandit.o: Bandit.cpp
	g++ -std=c++11 -c Bandit.cpp

Wolf.o: Wolf.cpp
	g++ -std=c++11 -c Wolf.cpp

InputValidation.o: InputValidation.cpp
	g++ -std=c++11 -c InputValidation.cpp

Player.o: Player.cpp
	g++ -std=c++11 -c Player.cpp

Merchant.o: Merchant.cpp
	g++ -std=c++11 -c Merchant.cpp

Die.o: Die.cpp
	g++ -std=c++11 -c Die.cpp

Object.o: Object.cpp
	g++ -std=c++11 -c Object.cpp

Water.o: Water.cpp
	g++ -std=c++11 -c Water.cpp 

Lumber.o: Lumber.cpp
	g++ -std=c++11 -c Lumber.cpp 

Hammer.o: Hammer.cpp
	g++ -std=c++11 -c Hammer.cpp 

Nails.o: Nails.cpp
	g++ -std=c++11 -c Nails.cpp 

Axe.o: Axe.cpp
	g++ -std=c++11 -c Axe.cpp 

Observation.o: Observation.cpp
	g++ -std=c++11 -c Observation.cpp

Board.o: Board.cpp
	g++ -std=c++11 -c Board.cpp

clean:
	rm *.o output