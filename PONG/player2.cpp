#pragma once
#include "player2.h"
#include "graphics.h"

void Player2::update()
{

	if (graphics::getKeyState(graphics::SCANCODE_LEFT)) {
		pos_x -= speed * graphics::getDeltaTime() / 10.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_RIGHT)) {
		pos_x += speed * graphics::getDeltaTime() / 10.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_UP)) {
		pos_y -= speed * graphics::getDeltaTime() / 10.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_DOWN)) {
		pos_y += speed * graphics::getDeltaTime() / 10.0f;
	}
	if (pos_x < CANVAS_WIDTH/2+30) pos_x = CANVAS_WIDTH/2+30;// ftiaxno ta oria
	if (pos_x > CANVAS_WIDTH) pos_x = CANVAS_WIDTH;
	if (pos_y > CANVAS_HEIGHT) pos_y = CANVAS_HEIGHT;
	if (pos_y < 0) pos_y = 0;
}

void Player2::draw()
{
	/*float glow = 0.5f + 0.5f * sinf(graphics::getGlobalTime()/10);// anabosbinei o player
	graphics::Brush br;

	br.texture = std::string(ASSET_PATH) + "spaceship.png";
	br.outline_opacity = 0.0f;*/


	/*graphics::setOrientation(-90.f);//girnaw 90 moires ton paikth
	graphics::drawRect(pos_x, pos_y, 100, 100, br);
	graphics::setOrientation(0.f);*/

	/*br.texture = "";
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;

	br.fill_secondary_color[0] = 0.3f;
	br.fill_secondary_color[1] = 0.1f;
	br.fill_secondary_color[2] = 0.0f;

	br.fill_opacity = 1.0f;

	br.fill_secondary_opacity = 0.0f;
	br.gradient = true;*/


	//graphics::drawDisk(pos_x-50, pos_y, 20, br);//eksatmisi
	graphics::Brush br;
	br.texture = "";
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;
	br.fill_opacity = 1.0f;
	graphics::drawRect(pos_x, pos_y, 5, 40, br);
}

void Player2::init()
{
}
