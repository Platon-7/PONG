#pragma once
#include "player.h"
#include "graphics.h"
#include "game.h"

Player::Player(const Game& mygame)
	: GameObject(mygame)
{
}

void Player::update()
{

	if (graphics::getKeyState(graphics::SCANCODE_W)) {
		pos_y -= speed * graphics::getDeltaTime() / 10.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_S)) {
		pos_y += speed * graphics::getDeltaTime() / 10.0f;
	}

	if (pos_y > CANVAS_HEIGHT-20) pos_y = CANVAS_HEIGHT-20;
	if (pos_y < 20) pos_y = 20;
}

void Player::draw()
{

	graphics::Brush br;
	br.texture = "";
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;
	br.fill_opacity = 1.0f;
	graphics::drawRect(pos_x, pos_y, 5, 40, br);

	br.outline_opacity = 1.0f;
	br.texture = "";
	br.fill_color[0] = 0.3f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 0.3f;
	br.fill_opacity = 0.0f;
	br.gradient = false;
	Rectangle rect = getCollisionRect();
	graphics::drawRect(rect.rx, rect.ry, rect.rw,rect.rh, br);
}

void Player::init()
{
}

Rectangle Player::getCollisionRect() const
{
	Rectangle rect;
	rect.rx = pos_x;
	rect.ry = pos_y;
	rect.rw = 5;
	rect.rh = 40;
	return rect;
}