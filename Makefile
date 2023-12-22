paths = test/*.cpp src/core/*.cpp

default: $(paths)
	rm -f main.exe
	g++ $(paths) -o main.exe -Iinclude -Llib -lsfml-graphics -lsfml-window -lsfml-system
	./main

