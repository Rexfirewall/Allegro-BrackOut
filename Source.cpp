#include <iostream>
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>

using namespace std;

const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int BOUNCER_SIZE = 32;
bool hit(int x1, int y1, int h1, int w1, int x2, int y2, int h2, int w2);

enum MYKEYS {
	KEY_LEFT, KEY_RIGHT
};

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
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	ALLEGRO_BITMAP *Ball = NULL;

	float bouncer_x = 295;
	float bouncer_y = 450;
	float Ball_x = 200;
	float Ball_y = 200;
	float Ball_dx = -4.0, Ball_dy = 4.0;
	bool key[4] = { false, false};
	bool redraw = true;
	bool doexit = false;





	al_init();
	al_init_primitives_addon();
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

			if (key[KEY_RIGHT] && bouncer_x >= 4.0) {
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

			if (hit(Ball_x, Ball_y, 32, 32, bouncer_x, bouncer_y, 32, 100) == true) {
				Ball_dx = -Ball_dx;
				Ball_dy = -Ball_dy;
			}

			redraw = true;
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
		/*else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		*/

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			b1.drawBrick();
			b2.drawBrick();
			b3.drawBrick();
			b4.drawBrick();
			b5.drawBrick();
			b6.drawBrick();
			b7.drawBrick();
			b8.drawBrick();
			b9.drawBrick();
			b10.drawBrick();
			b11.drawBrick();
			b12.drawBrick();
			b13.drawBrick();
			b14.drawBrick();
			b15.drawBrick();

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
}

void brick::drawBrick() {
	al_draw_rectangle(xPos, yPos, xPos + 80, yPos + 20, al_map_rgb(50, 200, 100), 5);
}

bool hit(int x1, int y1, int h1, int w1, int x2, int y2, int h2, int w2) {
	if ((x1 + w1 > x2) && (x1 < w2 + x1) && (y1 + h1 > y2) && (y1 < h2 + y2))
		return true;
	else
		return false;
}