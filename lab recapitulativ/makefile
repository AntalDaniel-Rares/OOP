CC = g++

build: main

main: *.cpp
	$(CC) -o $@ $^ -lm

run:
	./main

clean:
	rm -f main

exe:
	main run