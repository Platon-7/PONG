#pragma once
#include "gameobject.h"
#include "config.h"
class Player : public GameObject { // ginetai kai xwris klhronomikothta thn proteinoyme omws
	float speed = 10.0f;
	float pos_x = CANVAS_WIDTH/2, pos_y= CANVAS_HEIGHT/2;
public:
	void update() override;
	void draw() override;
	void init() override;
	float getPosY() { return pos_y; }
	float getPosX() { return pos_x; }
	// ton paikth tha ton ksekinhsw sthn update
};
