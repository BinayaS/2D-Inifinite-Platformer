all: solid player camera score background platformGen main exe

background: background.cpp
	g++ -c background.cpp

score: score.cpp
	g++ -c score.cpp

platformGen: platformGen.cpp
	g++ -c platformGen.cpp

camera: camera.cpp
	g++ -c camera.cpp

main: main.cpp
	g++ -c main.cpp

solid: solid.cpp
	g++ -c solid.cpp

player: player.cpp
		g++ -c player.cpp

exe:
	g++ -o "RunCubeRUN!!" \
	solid.o \
	player.o \
	camera.o \
	score.o \
	background.o \
	platformGen.o \
	main.o \
	-lsfml-graphics \
	-lsfml-window \
	-lsfml-system

clean:
	rm "RunCubeRUN!!"
	rm camera.o
	rm score.o
	rm solid.o
	rm player.o
	rm main.o
	rm platformGen.o
	rm background.o
