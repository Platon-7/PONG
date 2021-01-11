#include "ball.h"
#include "graphics.h"
#include <iostream>
#include "util.h"
#include <string>
#include <vecmath.h>
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>

void Ball::update()
{
	if (hits > x) {
		ball_speed = ball_speed * 1.5f;
		x = x + 10;
	}


	spinner_angle++;

	ball_future_center_x = ball_center_x + ball_direction_x * ball_speed;
	ball_future_center_y = ball_center_y + ball_direction_y * ball_speed;


	/*if ((ball_future_center_x + ball_radius) >= canvas_width) {
		math::vec2 dir{ ball_direction_x, ball_direction_y };
		math::vec2 normal = { -1.0f, 0.0f };
		math::vec2 reflection = math::reflect(dir, normal);
		ball_direction_x = reflection.x;
		ball_direction_y = reflection.y;
		play_collision_sound = true;
	}

	if ((ball_future_center_x - ball_radius) <= 0.0f) {
		math::vec2 dir{ ball_direction_x, ball_direction_y };
		math::vec2 normal = { 1.0f, 0.0f };
		math::vec2 reflection = math::reflect(dir, normal);
		ball_direction_x = reflection.x;
		ball_direction_y = reflection.y;
		play_collision_sound = true;
	}*/
	if ((ball_future_center_y + ball_radius) >= canvas_height) {
		math::vec2 dir{ ball_direction_x, ball_direction_y };
		math::vec2 normal = { 0.0f, -1.0f };
		math::vec2 reflection = math::reflect(dir, normal);
		ball_direction_x = reflection.x;
		ball_direction_y = reflection.y;

	}
	else if ((ball_future_center_y - ball_radius) <= 0.0f) {
		math::vec2 dir{ ball_direction_x, ball_direction_y };
		math::vec2 normal = { 0.0f, 1.0f };
		math::vec2 reflection = math::reflect(dir, normal);
		ball_direction_x = reflection.x;
		ball_direction_y = reflection.y;

	}

	ball_center_x += ball_direction_x * ball_speed;
	ball_center_y += ball_direction_y * ball_speed;

}
void Ball::hitBarrier()
{

	math::vec2 dir{ ball_direction_x, ball_direction_y };
	math::vec2 normal = { -1.0f, 0.0f };
	math::vec2 reflection = math::reflect(dir, normal);
	ball_direction_x = reflection.x;
	ball_direction_y = reflection.y;
	play_collision_sound = true;



}
void Ball::hit()
{


	math::vec2 dir{ ball_direction_x, ball_direction_y };
	math::vec2 normal = { -1.0f, 0.0f };
	math::vec2 reflection = math::reflect(dir, normal);
	ball_direction_x = reflection.x;
	ball_direction_y = reflection.y;
	play_collision_sound = true;
	hits++;
	ball_center_x += ball_direction_x * ball_speed;
	ball_center_y += ball_direction_y * ball_speed; 

	if (play_collision_sound) {
		std::string wav = std::string(ASSET_PATH) + "pong_hit_edited.wav";
		graphics::playSound(wav, 0.5f);
	}



}

void Ball::drawBall()
{
	graphics::setOrientation(spinner_angle);
	br.fill_color[0] = 1.1f;
	br.fill_color[1] = 1.1f;
	br.fill_color[2] = 1.1f;
	//br.fill_opacity = 1.0f;
	br.outline_opacity = 0.0f;
	graphics::drawDisk(ball_center_x, ball_center_y, ball_radius, br);
	graphics::resetPose();




}
void Ball::drawSpinner() {

	graphics::Brush br;
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;
	br.fill_opacity = 1.0f;

	graphics::setOrientation(spinner_angle);
	//graphics::drawSector(90, 10, 2, 5, 0, 90, br);
	graphics::setOrientation(0);
}


void Ball::init()
{
	int u = 0;
	int min = 1;
	int max = 249;
	float r = rand0to1();
	float value =  min + r * (max - min);
	float result = randOper(CANVAS_HEIGHT/2, value);
	ball_center_x = CANVAS_WIDTH/2;
	ball_center_y = result; ///bgainei apo to kentro kai paei eite pros ta aristera eite pros ta deksia
	rangeRandom(ball_radius, CANVAS_HEIGHT - ball_radius);
	while (u == 0) {
		float local = randOper(0, 1);
		ball_direction_x = local * rand0to1();
		ball_direction_y = local * rand0to1();
		// Normalize
		float length = std::sqrt(ball_direction_x * ball_direction_x + ball_direction_y * ball_direction_y);
		ball_direction_x /= length;
		ball_direction_y /= length;
		//ekstra elegxos
		if (std::abs(ball_direction_y) - std::abs(ball_direction_x) <= 0.4) {
			u++;
		}
	}
}
void Ball::draw()
{
	drawBall();

}


Disk Ball::getCollisionHull() const
{
	Disk disk;
	disk.cx = ball_center_x;
	disk.cy = ball_center_y;
	disk.radius = 4.0f;
	return disk;
}


Ball::Ball(const Game& mygame)
	: GameObject(mygame)
{
	init();
}
Ball::~Ball()
{

}