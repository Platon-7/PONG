#include "ball.h"
#include "graphics.h"
#include <iostream>
#include "util.h"
#include <string>
#include <vecmath.h>
#include "game.h"

void Ball::update()
{


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
void Ball::hit()
{
	spinner_angle++;
	ball_future_center_x = ball_center_x + ball_direction_x * ball_speed;
	ball_future_center_y = ball_center_y + ball_direction_y * ball_speed;
	play_collision_sound = false;

	if ((ball_future_center_x + ball_radius) >= canvas_width - 47.5) {
	math::vec2 dir{ ball_direction_x, ball_direction_y };
	math::vec2 normal = { -1.0f, 0.0f };
	math::vec2 reflection = math::reflect(dir, normal);
	ball_direction_x = reflection.x;
	ball_direction_y = reflection.y;
	play_collision_sound = true;
	}

	if ((ball_future_center_x - ball_radius) <= 47.5) {
		math::vec2 dir{ ball_direction_x, ball_direction_y };
		math::vec2 normal = { 1.0f, 0.0f };
		math::vec2 reflection = math::reflect(dir, normal);
		ball_direction_x = reflection.x;
		ball_direction_y = reflection.y;
		play_collision_sound = true;
	}
	if (play_collision_sound) {
		std::string wav = std::string(ASSET_PATH) + "pong_hit_edited.wav";
		graphics::playSound(wav, 0.5f);
	}
	ball_center_x += ball_direction_x * ball_speed;
	ball_center_y += ball_direction_y * ball_speed;

	/*math::vec2 dir{ ball_direction_x, ball_direction_y };
	math::vec2 normal = { -1.0f, 0.0f };
	math::vec2 reflection = math::reflect(dir, normal);
	ball_direction_x = reflection.x;
	ball_direction_y = reflection.y;
	play_collision_sound = true;
	/*spinner_angle++;
	ball_future_center_x = ball_center_x + ball_direction_x * ball_speed;
	ball_future_center_y = ball_center_y + ball_direction_y * ball_speed;
	play_collision_sound = false;

	if ((ball_future_center_x + ball_radius) >= canvas_width) {
		math::vec2 dir{ ball_direction_x, ball_direction_y };
		math::vec2 normal = { -1.0f, 0.0f };
		math::vec2 reflection = math::reflect(dir, normal);
		ball_direction_x = reflection.x;
		ball_direction_y = reflection.y;
		play_collision_sound = true;
	}

	else if ((ball_future_center_x - ball_radius) <= 0.0f) {
		math::vec2 dir{ ball_direction_x, ball_direction_y };
		math::vec2 normal = { 1.0f, 0.0f };
		math::vec2 reflection = math::reflect(dir, normal);
		ball_direction_x = reflection.x;
		ball_direction_y = reflection.y;
		play_collision_sound = true;
	}
	if ((ball_future_center_y + ball_radius) >= canvas_height) {
		math::vec2 dir{ ball_direction_x, ball_direction_y };
		math::vec2 normal = { 0.0f, -1.0f };
		math::vec2 reflection = math::reflect(dir, normal);
		ball_direction_x = reflection.x;
		ball_direction_y = reflection.y;
		play_collision_sound = true;
	}
	else if ((ball_future_center_y - ball_radius) <= 0.0f) {
		math::vec2 dir{ ball_direction_x, ball_direction_y };
		math::vec2 normal = { 0.0f, 1.0f };
		math::vec2 reflection = math::reflect(dir, normal);
		ball_direction_x = reflection.x;
		ball_direction_y = reflection.y;
		play_collision_sound = true;
	}
	if (play_collision_sound) {
		std::string wav = std::string(ASSET_PATH) + "pong_hit_edited.wav";
		graphics::playSound(wav, 0.5f);
	}
	ball_center_x += ball_direction_x * ball_speed;
	ball_center_y += ball_direction_y * ball_speed;*/
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

	/*graphics::Brush brush;
	brush.outline_opacity = 1.0f;
	brush.texture = "";
	brush.fill_color[0] = 0.3f;
	brush.fill_color[1] = 1.0f;
	brush.fill_color[2] = 0.3f;
	brush.fill_opacity = 0.0f;
	brush.gradient = false;
	Disk hull = getCollisionHull();
	graphics::drawDisk(hull.cx, hull.cy, hull.radius, brush);*/


}

void Ball::init()
{
	if (myball == 0) {
		ball_center_x = CANVAS_HEIGHT - 50 + rand0to1();
		ball_center_y = CANVAS_HEIGHT - 50 + rand0to1();//bgainei apo to kentro kai paei eite pros ta aristera eite pros ta deksia
		ball_direction_x = rand0to1();
		ball_direction_y = rand0to1();
	}
	else {
		ball_center_x = CANVAS_HEIGHT - 50 + rand0to1();
		ball_center_y = CANVAS_HEIGHT - 50 + rand0to1();//bgainei apo to kentro kai paei eite pros ta aristera eite pros ta deksia
		ball_direction_x = -1*rand0to1();
		ball_direction_y = -1*rand0to1();
	}

	// Normalize
	float length = std::sqrt(ball_direction_x * ball_direction_x + ball_direction_y * ball_direction_y);
	ball_direction_x /= length;
	ball_direction_y /= length;
	myball++;
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
	/*if (abs(x - ball_center_x)>ball_radius/2) {
		disk.cy = ball_future_center_y;
		disk.cx = ball_future_center_x;
	}
	else {
		float offset = (ball_future_center_x - x) / ball_direction_x;
		disk.cy = ball_future_center_y - (ball_direction_y * offset);
		disk.cx = x;
		disk.radius = 4.0f;;
	}*/
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