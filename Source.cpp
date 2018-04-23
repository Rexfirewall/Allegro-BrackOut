#include <iostream>
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
//#include <allegro5\allegro_audio.h>
//#include <allegro5\allegro_acodec.h>
#include <allegro5/allegro_image.h>

using namespace std;

const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int BOUNCER_SIZE = 32;
bool hit(int x1, int y1, int h1, int w1, int x2, int y2, int h2, int w2);

//bool key[2] = { false, false };

enum MYKEYS {
	KEY_LEFT, KEY_RIGHT
};

class brick {
private:
	int xPos;
	int yPos;
	bool isdead;
public:
	void initBrick(int x, int y);
	void drawBrick();
	bool brickcollision(int ballx, int bally, int ballw, int ballh);
	void kill();
	bool dead();
};

int main() {
	ALLEGRO_DISPLAY *win = NULL;
	ALLEGRO_DISPLAY *BackGroundPIC = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	ALLEGRO_BITMAP *Ball = NULL;

	float bouncer_x = 295;
	float bouncer_y = 425;
	float Ball_x = 300;
	float Ball_y = 350;
	float Ball_dx = -4.0, Ball_dy = 4.0;
	bool key[4] = { false, false};
	bool redraw = true;
	bool doexit = false;





	al_init();
	al_init_primitives_addon();
	al_init_image_addon();
	al_install_keyboard();
	
	timer = al_create_timer(1.0 / FPS);

	win = al_create_display(SCREEN_W, SCREEN_H);

	bouncer = al_create_bitmap(100, 20);
	Ball = al_create_bitmap(20, 20);

	al_set_target_bitmap(Ball);
	al_clear_to_color(al_map_rgb(158, 48, 123));

	al_set_target_bitmap(bouncer);
	al_clear_to_color(al_map_rgb(255, 0, 255));

	al_set_target_bitmap(al_get_backbuffer(win));

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(win));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));






	brick b1;
	brick b2;
	brick b3;
	brick b4;
	brick b5;
	brick b6;
	brick b7;
	brick b8;
	brick b9;
	brick b10;
	brick b11;
	brick b12;
	brick b13;
	brick b14;
	brick b15;

	b1.initBrick(50, 50);
	b2.initBrick(150, 50);
	b3.initBrick(250, 50);
	b4.initBrick(350, 50);
	b5.initBrick(450, 50);
	b6.initBrick(100, 100);
	b7.initBrick(200, 100);
	b8.initBrick(300, 100);
	b9.initBrick(400, 100);
	b10.initBrick(155, 150);
	b11.initBrick(255, 150);
	b12.initBrick(355, 150);
	b13.initBrick(210, 200);
	b14.initBrick(310, 200);
	b15.initBrick(260, 250);



	al_start_timer(timer);

	while (!doexit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {

			if (key[KEY_LEFT] && bouncer_x >= 4.0) {
			bouncer_x -= 4.0;
			}

			if (key[KEY_RIGHT] && bouncer_x <= SCREEN_W - 100 - 4.0) {
				bouncer_x += 4.0;
			}

			if (Ball_x < 0 || Ball_x > 640 - 32) {
				Ball_dx = -Ball_dx;
			}

			if (Ball_y < 0 || Ball_y > 480 - 32) {
				Ball_dy = -Ball_dy;
			}

			Ball_x += Ball_dx;
			Ball_y += Ball_dy;

			if (hit(Ball_x, Ball_y, 20, 20, bouncer_x, bouncer_y, 20, 100) == true) {
				Ball_dx = -Ball_dx;
				Ball_dy = -Ball_dy;
			}

			redraw = true;

			if (hit(Ball_x, Ball_y, 15, 15, bouncer_x, bouncer_y, 20, 20)) {
				Ball_dy = -Ball_dy;
			}

			if (b1.dead() == false && b1.brickcollision(Ball_x, Ball_y, 20, 20) == true) {
				Ball_dy = -Ball_dy;
				b1.kill();
			}
			if (b2.dead() == false && b2.brickcollision(Ball_x, Ball_y, 20, 20) == true) {
				Ball_dy = -Ball_dy;
				b2.kill();
			}
			if (b3.dead() == false && b3.brickcollision(Ball_x, Ball_y, 20, 20) == true) {
				Ball_dy = -Ball_dy;
				b3.kill();
			}
			if (b4.dead() == false && b4.brickcollision(Ball_x, Ball_y, 20, 20) == true) {
				Ball_dy = -Ball_dy;
				b4.kill();
			}
			if (b5.dead() == false && b5.brickcollision(Ball_x, Ball_y, 20, 20) == true) {
				Ball_dy = -Ball_dy;
				b5.kill();
			}
			if (b6.dead() == false && b6.brickcollision(Ball_x, Ball_y, 20, 20) == true) {
				Ball_dy = -Ball_dy;
				b6.kill();
			}
			if (b7.dead() == false && b7.brickcollision(Ball_x, Ball_y, 20, 20) == true) {
				Ball_dy = -Ball_dy;
				b7.kill();
			}
			if (b8.dead() == false && b8.brickcollision(Ball_x, Ball_y, 20, 20) == true) {
				Ball_dy = -Ball_dy;
				b8.kill();
			}
			if (b9.dead() == false && b9.brickcollision(Ball_x, Ball_y, 20, 20) == true) {
				Ball_dy = -Ball_dy;
				b9.kill();
			}
			if (b10.dead() == false && b10.brickcollision(Ball_x, Ball_y, 20, 20) == true) {
				Ball_dy = -Ball_dy;
				b10.kill();
			}
			if (b11.dead() == false && b11.brickcollision(Ball_x, Ball_y, 20, 20) == true) {
				Ball_dy = -Ball_dy;
				b11.kill();
			}
			if (b12.dead() == false && b12.brickcollision(Ball_x, Ball_y, 20, 20) == true) {
				Ball_dy = -Ball_dy;
				b12.kill();
			}
			if (b13.dead() == false && b13.brickcollision(Ball_x, Ball_y, 20, 20) == true) {
				Ball_dy = -Ball_dy;
				b13.kill();
			}
			if (b14.dead() == false && b14.brickcollision(Ball_x, Ball_y, 20, 20) == true) {
				Ball_dy = -Ball_dy;
				b14.kill();
			}
			if (b15.dead() == false && b15.brickcollision(Ball_x, Ball_y, 20, 20) == true) {
				Ball_dy = -Ball_dy;
				b15.kill();
			}
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = true;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = true;
				break;

			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = false;
				break;

			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;


			}
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			if (b1.dead() == false) {
				b1.drawBrick();
			}
			if (b2.dead() == false) {
				b2.drawBrick();
			}
			if (b3.dead() == false) {
				b3.drawBrick();
			}
			if (b4.dead() == false) {
				b4.drawBrick();
			}
			if (b5.dead() == false) {
				b5.drawBrick();
			}
			if (b6.dead() == false) {
				b6.drawBrick();
			}
			if (b7.dead() == false) {
				b7.drawBrick();
			}
			if (b8.dead() == false) {
				b8.drawBrick();
			}
			if (b9.dead() == false) {
				b9.drawBrick();
			}
			if (b10.dead() == false) {
				b10.drawBrick();
			}
			if (b11.dead() == false) {
				b11.drawBrick();
			}
			if (b12.dead() == false) {
				b12.drawBrick();
			}
			if (b13.dead() == false) {
				b13.drawBrick();
			}
			if (b14.dead() == false) {
				b14.drawBrick();
			}
			if (b15.dead() == false) {
				b15.drawBrick();
			}

			al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);
			al_draw_bitmap(Ball, Ball_x, Ball_y, 0);

			al_flip_display();
		}
	}
	al_destroy_bitmap(bouncer);
	al_destroy_bitmap(Ball);
	al_destroy_timer(timer);
	al_destroy_display(win);
	al_destroy_event_queue(event_queue);

	return 0;
}

void brick::initBrick(int x, int y) {
	xPos = x;
	yPos = y;
	isdead = false;
}

void brick::drawBrick() {
	al_draw_rectangle(xPos, yPos, xPos + 80, yPos + 20, al_map_rgb(50, 200, 100), 5);
}

bool hit(int x1, int y1, int h1, int w1, int x2, int y2, int h2, int w2) {
	if ((x1 + w1 > x2) && (x1 < x2 + w2) && (y1 + h1 > y2) && (y1 < h2 + y2))
		return true;
	else
		return false;
}

bool brick::brickcollision(int ballx, int bally, int ballw, int ballh) {
	if ((xPos + 80 > ballx) && (ballx + 20 > xPos) && (bally +20 > yPos) && (yPos +20 >bally))
		return true;
	else
		return false;
}

bool brick::dead() {
	return isdead;
}

void brick::kill() {
	isdead = true;
}