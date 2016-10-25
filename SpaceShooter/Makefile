CC=g++
LIBS= -lsfml-graphics -lsfml-window -lsfml-system -std=c++11

all: spaceshooter

spaceshooter: main.cpp Enemy.cpp Player.cpp Background.cpp Projectile.cpp
	$(CC) -o spaceshooter main.cpp Enemy.cpp Player.cpp Background.cpp Projectile.cpp $(LIBS)

clean:
	rm -rf spaceshooter
