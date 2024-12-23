all: buttle_shipp

buttle_shipp: main.o segment.o ship.o manager.o gameboard.o scanner.o doubledamage.o barrage.o abilitymanager.o customexept.o game.o gamestate.o printer.o printerTerminal.o reader.o gamemanager.o file.o
	g++ main.o segment.o ship.o manager.o gameboard.o scanner.o doubledamage.o barrage.o abilitymanager.o customexept.o game.o gamestate.o printer.o printerTerminal.o reader.o gamemanager.o file.o -o buttle_shipp

main.o: main.cpp manager.h gameboard.h scanner.h doubledamage.h barrage.h abilitymanager.h customexept.h game.h gamestate.h printer.h printerTerminal.h reader.h gamemanager.h
	g++ -c main.cpp

segment.o: segment.cpp segment.h
	g++ -c segment.cpp

ship.o: ship.cpp ship.h segment.h
	g++ -c ship.cpp

manager.o: manager.cpp manager.h ship.h
	g++ -c manager.cpp

gameboard.o: gameboard.cpp gameboard.h 
	g++ -c gameboard.cpp

scanner.o: scanner.cpp scanner.h vability.h
	g++ -c scanner.cpp

doubledamage.o: doubledamage.cpp doubledamage.h vability.h
	g++ -c doubledamage.cpp

barrage.o: barrage.cpp barrage.h vability.h
	g++ -c barrage.cpp

abilitymanager.o: abilitymanager.cpp abilitymanager.h 
	g++ -c abilitymanager.cpp

customexept.o: customexept.cpp customexept.h
	g++ -c customexept.cpp	

game.o: game.cpp game.h
	g++ -c game.cpp

gamestate.o: gamestate.cpp gamestate.h
	g++ -c gamestate.cpp

printer.o: printer.cpp printer.h
	g++ -c printer.cpp

printerTerminal.o: printerTerminal.cpp printerTerminal.h
	g++ -c printerTerminal.cpp

reader.o: reader.cpp reader.h
	g++ -c reader.cpp

gamemanager.o: gamemanager.cpp gamemanager.h
	g++ -c gamemanager.cpp

file.o: file.h file.cpp
	g++ -c file.cpp

clean: 
	rm *.o buttle_shipp