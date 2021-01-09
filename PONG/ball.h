#pragma once
#include "gameobject.h"
#include "config.h"
#include "graphics.h"

class Ball : public GameObject, public Collidable {

	int myball = 0;
	graphics::Brush br;
	/*float pos_x, pos_y;
	float speed;
	float size;
	float rotation;*/
	bool active = true;

	int leftscore = 0;
	int rightscore = 0;

	float canvas_width = CANVAS_WIDTH;
	float canvas_height = CANVAS_HEIGHT;
	float ball_center_x;
	float ball_center_y;
	float ball_direction_x;
	float ball_direction_y;
	float ball_radius = 4.0f;
	float ball_future_center_y;
	float ball_future_center_x;
	bool play_collision_sound;

	float ball_speed = 2.0f;

	float spinner_angle = 0.0f;

public:
	void update() override;
	void draw() override;
	void init() override;
	void drawScore();
	void drawBall();
	void hit();
	bool ballActive() {
		return active;
	}
	float getPosY() { return ball_center_y; }
	float getPosX() { return ball_center_x; }
	Disk getCollisionHull() const override;

	Ball(const class Game& mygame);
	~Ball();
};