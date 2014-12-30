all:
		g++ src/main.cpp src/UnitTests.cpp src/Grid.cpp src/Utils.cpp src/Cell.cpp src/GfxWrapper.cpp -o bin/KataGameOfLife -lsfml-graphics -lsfml-window -lsfml-system -lGL `pkg-config --cflags --libs cairo gtk+-3.0` 
clean:
		rm -rf bin/KataGameOfLife