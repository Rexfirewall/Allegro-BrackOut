#include <allegro5\allegro.h>
#include <allegro5/allegro_primitives.h>

class brick {
private:
	int xPos;
	int yPos;
public:
	void initBrick(int x, int y);
	void drawBrick();
};

int main() {
	ALLEGRO_DISPLAY *win = NULL;

	al_init();
	al_init_primitives_addon();

	win = al_create_display(600, 600);


	brick b1;
	brick b2;
	brick b3;

	b1.initBrick(50, 50);
	b2.initBrick(100, 100);
	b3.initBrick(200, 200);

	b1.drawBrick();
	b2.drawBrick();
	b3.drawBrick();

	al_flip_display();
	al_rest(20);
	al_destroy_display(win);
}

void brick::initBrick(int x, int y) {
	xPos = x;
	yPos = y;
}

void brick::drawBrick() {
	al_draw_rectangle(xPos, yPos, xPos + 80, yPos + 20, al_map_rgb(50, 200, 100), 5);
}