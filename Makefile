main: main.o HeavyHitter.o
	g++ -g main.o HeavyHitter.o -o main

main.o: main.cpp HeavyHitter.h
	g++ -g main.cpp -c

HeavyHitter.o: HeavyHitter.h HeavyHitter.cpp
	g++ -g HeavyHitter.cpp -c

clean:
	rm main.o HeavyHitter.o main 
