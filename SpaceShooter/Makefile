CC=g++
LIBS= -lsfml-graphics -lsfml-window -lsfml-system -std=c++11
LLIBS= -ggdb -g -ansi -pedantic -W -Wall -lsfml-graphics -lsfml-window -lsfml-system -std=c++11

all: spaceshooter spaceshooter-dbg

spaceshooter: main.cpp Enemy.cpp Player.cpp Background.cpp Projectile.cpp
	$(CC) -o spaceshooter main.cpp Enemy.cpp Player.cpp Background.cpp Projectile.cpp $(LIBS)

spaceshooter-dbg: main.cpp Enemy.cpp Player.cpp Background.cpp Projectile.cpp
	$(CC) -o spaceshooter-dbg main.cpp Enemy.cpp Player.cpp Background.cpp Projectile.cpp $(LLIBS)

clean:
	rm -rf spaceshooter
	rm -rf spaceshooter-dbg
