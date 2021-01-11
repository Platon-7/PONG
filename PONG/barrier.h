#pragma once
#include "gameobject.h"
#include "config.h"

class Barrier : public GameObject, public Collidable { // ginetai kai xwris klhronomikothta thn proteinoyme omws
	//float pos_x= (float)rangeRandom(250, 750);
	//float pos_y= (float)rangeRandom(radius, CANVAS_HEIGHT - radius);
	//float radius= rangeRandom(30, 100);
	float pos_x = CANVAS_WIDTH / 2;
	float pos_y = CANVAS_HEIGHT / 2;
	float radius = 50.0f;
public:
	Barrier(const class Game& mygame);
	void update() override;
	void draw() override;
	void init() override;
	float getBarrierPosY() { return pos_x; }
	float getBarrierPosX() { return pos_y; }
	Disk getCollisionHull() const override;
	// ton paikth tha ton ksekinhsw sthn update
};