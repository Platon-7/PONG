#pragma once
#include "player.h"
#include "graphics.h"

void Player::update()
{
}

void Player::draw()
{
	float glow = 0.5f + 0.5f * sinf(graphics::getGlobalTime()/10);// anabosbinei o player
	graphics::Brush br;
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 0.5f + glow*0.5;
	br.fill_color[2] = 0.0f;

	br.fill_secondary_color[0] = 0.3f;
	br.fill_secondary_color[1] = 0.1f;
	br.fill_secondary_color[2] = 0.0f;

	br.fill_opacity = 1.0f;

	br.fill_secondary_opacity = 0.0f;
	br.gradient = true;
	br.outline_opacity = 0;

	graphics::drawDisk(pos_x, pos_y, 60, br);
}

void Player::init()
{
}
