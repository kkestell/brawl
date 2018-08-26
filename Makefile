game: src/main.c src/sprite.c src/level.c src/input.c src/entity.c
	cc -Wall -o bin/brawl \
		src/main.c \
		src/sprite.c \
		src/level.c \
		src/input.c \
		src/entity.c \
		-lm -lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf

tools: src/tools/make_sprite.c src/tools/animed.c src/sprite.c
	cc -Wall -o bin/make_sprite src/tools/make_sprite.c -lm -lSDL2 -lSDL2main
	cc -Wall -o bin/animed src/tools/animed.c src/sprite.c -lm -lSDL2 -lSDL2main -lSDL2_image  -lSDL2_ttf

clean:
	rm bin/brawl bin/make_sprite