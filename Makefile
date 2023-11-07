testFiles := tests/*.cpp
files := tse/core/*.cpp tse/math/*.cpp tse/renderer/*.cpp
libs := -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lmingw32

test: $(files)
	rm -f main.exe
	g++ -Iinclude -Llib -o main $(testFiles) $(files) $(libs)
	./main

retest: ./main.exe
	./main