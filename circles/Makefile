CC = gcc
OBJS = $(patsubst %.c,%.o,$(wildcard src/*.c))
CFLAGS = -Wall -Wextra -g `sdl2-config --cflags`
LDFLAGS = -lm -lSDL2_mixer -lSDL2_ttf -lSDL2_gfx -lSDL2_image `sdl2-config --libs`
EXEC = circles
images = assets/background.png assets/difficulty.png assets/easy.png assets/hard.png assets/medium.png assets/play.png assets/quit.png assets/title.png assets/earth.png assets/player.png
minified_images = $(patsubst %.png,%-small.png,$(images))

.PHONY: sdl digits minify html run leak clean

$(EXEC): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)
	
%.o: %.c
	$(CC) -o $@ $< $(CFLAGS) -c

digits:
	convert digits.png -scale 12.5% digits-small.png

minify: $(minified_images)

%-small.png: %.png
	convert $< -scale 50% $@

html:
	@echo "generating html documentation..."
	@pandoc --metadata pagetitle="Le jeu Circles" \
			-f markdown -o README.html \
			-sc github-pandoc.css \
			README.md
	@echo "done"

run: $(EXEC)
	./$(EXEC)

leak: $(EXEC)
	valgrind --leak-check=full ./circles

clean:
	rm -f $(OBJS) $(EXEC)
