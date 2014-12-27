all:
		g++ src/main.cpp src/UnitTests.cpp src/Grid.cpp src/Utils.cpp src/Cell.cpp -o bin/KataGameOfLife
clean:
		rm -rf bin/KataGameOfLife