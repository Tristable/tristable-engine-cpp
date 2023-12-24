paths = test/*.cpp src/core/*.cpp
flags = -Iinclude -Llib -lsfml-graphics -lsfml-window -lsfml-system
output = main.exe

default: $(paths)
	rm -f $(output)
	g++ $(paths) -o $(output) $(flags)
	./$(output)

retest: $(output)
	./$(output)

build: $(paths)
	rm -f $(output)
	g++ $(paths) -o $(output) $(flags)