#pragma once
#include "graphics.h"
#include "game.h"
#include "barrier.h"
#include "util.h"

Barrier::Barrier(const Game& mygame)
	: GameObject(mygame)
{
}

void Barrier::update()
{

}

void Barrier::draw()
{
	graphics::Brush br;
	br.texture = "";
	br.fill_color[0] = 1.1f;
	br.fill_color[1] = 1.1f;
	br.fill_color[2] = 1.1f;
	br.fill_opacity = 1.0f;
	br.outline_opacity = 0.0f;
	graphics::drawDisk(pos_x, pos_y, radius, br);
	graphics::resetPose();

}

void Barrier::init()
{

}


Disk Barrier::getCollisionHull() const
{
	Disk disk;
	disk.cx = pos_x;
	disk.cy = pos_y;
	disk.radius = radius;
	return disk;
}