#pragma once
#include "gameobject.h"
#include "config.h"

class Player2 : public GameObject, public Collidable3 { // ginetai kai xwris klhronomikothta thn proteinoyme omws
	float speed = 2.0f;
	float pos_x = CANVAS_WIDTH - 50, pos_y = CANVAS_HEIGHT / 2;
public:
	Player2(const class Game& mygame);
	void update() override;
	void draw() override;
	void init() override;
	// ton paikth tha ton ksekinhsw sthn update
	Rectangle getCollisionRect() const override;
};