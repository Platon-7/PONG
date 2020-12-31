#include "gameobject.h"
#include "config.h"
#include "graphics.h"

class Ball : public GameObject {

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

	float ball_speed = 2.5f;

	float spinner_angle = 0.0f;
public:
	void update() override;
	void draw() override;
	void init() override;
	void drawScore();
	void drawBall();
	bool ballActive(){
		return active;
	}
	Ball();
	~Ball();
};


