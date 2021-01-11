#pragma once
#include "graphics.h"
#include "game.h"
#include "barrier.h"
#include "util.h"
#include "ball.h"

Barrier::Barrier(const Game& mygame)
	: GameObject(mygame)
{
	init();
}

void Barrier::update()
{
// h update den exei kapoia xrhsh giati to barrier apla kanei spawn kai ginetai destroy se xronika diasthmata tyxaia poy orizontai sth game.cpp

}

void Barrier::draw()
{
	br.fill_color[0] = 1.1f;
	br.fill_color[1] = 1.1f;
	br.fill_color[2] = 1.1f;
	br.fill_opacity = 1.0f;
	br.outline_opacity = 0.0f;
	graphics::drawDisk(pos_x, pos_y, radius, br);

}


void Barrier::init()
{
	radius = rangeRandom(30, 100);
	pos_x = (float)rangeRandom(250, 750);// pairnw tyxaia megethi kai tyxaies theseis gia thn mpala 
	pos_y = (float)rangeRandom(radius, CANVAS_HEIGHT - radius);
}


Disk Barrier::getCollisionHull() const
{
	Disk disk;
	disk.cx = pos_x;
	disk.cy = pos_y;
	disk.radius = radius;
	return disk;
}