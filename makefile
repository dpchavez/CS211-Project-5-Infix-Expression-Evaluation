Project5: TheStack.o main.o
	g++ -o Project5 TheStack.o main.o
TheStack.o: TheStack.cpp TheStack.h
	g++ -c TheStack.cpp
main.o: main.cpp TheStack.h
	g++ -c main.cpp
Debug:
	./program.exe -d

