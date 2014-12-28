all:
		g++ src/main.cpp src/UnitTests.cpp src/Grid.cpp src/Utils.cpp src/Cell.cpp src/GTKWrapper.cpp -o bin/KataGameOfLife `pkg-config --cflags --libs cairo gtk+-3.0` 
clean:
		rm -rf bin/KataGameOfLife