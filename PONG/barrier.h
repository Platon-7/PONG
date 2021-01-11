#pragma once
#include "gameobject.h"
#include "config.h"

class Barrier : public GameObject, public Collidable { // ginetai kai xwris klhronomikothta thn proteinoyme omws
	graphics::Brush br;
	float pos_x = CANVAS_WIDTH / 2;// otan den dinw arxikes times to programma crasharei ara dinw edw tyxaies times stis metablhtes kai outws h allws sthn init() tha allaksoyn se tuxaies ypologismenes apo th rangeRandom
	float pos_y = CANVAS_HEIGHT / 2;
	float radius = 50.0f;
public:
	Barrier(const class Game& mygame);
	void update() override;
	void draw() override;
	void init() override;
	float getBarrierPosY() { return pos_x; }
	float getBarrierPosX() { return pos_y; }
	float getBarrierRadius() { return radius; }
	Disk getCollisionHull() const override;

};