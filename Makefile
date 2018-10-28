main: main.o HeavyHitter.o
	g++ -g main.o HeavyHitter.o -o main

main.o: main.cpp HeavyHitter.h
	g++ -g main.cpp -c

HeavyHitter.o: HeavyHitter.h HeavyHitter.cpp
	g++ -g HeavyHitter.cpp -c

testMinHeap: testMinHeap.o HeavyHitter.o
	g++ -g testMinHeap.o HeavyHitter.o -o testMinHeap

testMinHeap.o: testMinHeap.cpp HeavyHitter.h
	g++ -g testMinHeap.cpp -c

testTable: testTable.o HeavyHitter.o
	g++ -g testTable.o HeavyHitter.o -o testTable

testTable.o: testTable.cpp HeavyHitter.h
	g++ -g testTable.cpp -c

clean:
	/bin/rm -f *.o main testMinHeap testTable
