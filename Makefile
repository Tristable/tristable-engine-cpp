testFiles := tests/*.cpp
files := tse/core/*.cpp tse/math/*.cpp tse/renderer/*.cpp
libs := -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

test: $(files)
	rm -f main.exe
	g++ -L lib -o main $(testFiles) $(files) $(libs)
	./main