all:
		g++ src/main.cpp src/UnitTests.cpp src/Grid.cpp src/Utils.cpp src/Cell.cpp src/GfxWrapper.cpp src/GfxCell.cpp -o bin/KataGameOfLife -lsfml-graphics -lsfml-window -lsfml-system -lGL
clean:
		rm -rf bin/KataGameOfLife