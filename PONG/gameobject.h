#pragma once
#include "util.h"

class Collidable
{
public:
	virtual Disk getCollisionHull() const = 0;

};
class Collidable2 {
public:
	virtual Line getCollisionLine() const = 0;
};
class Collidable3 {
public:
	virtual Rectangle getCollisionRect() const = 0;
};


class GameObject {
protected:
	const class Game& game;
public:
	GameObject(const class Game& mygame);
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void init() = 0;
};