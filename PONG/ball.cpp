#include "ball.h"
#include "graphics.h"
#include <iostream>
#include "util.h"
#include <string>
#include <vecmath.h>


void Ball::update()
{


	spinner_angle++;

	float ball_future_center_x = ball_center_x + ball_direction_x *ball_speed;
	float ball_future_center_y = ball_center_y + ball_direction_y * ball_speed;
	bool play_collision_sound = false;


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
		std::string wav= std::string(ASSET_PATH) + "pong_hit_edited.wav";
		graphics::playSound(wav, 0.5f);
	}
	ball_center_x += ball_direction_x * ball_speed;
	ball_center_y += ball_direction_y * ball_speed;

}

void Ball::drawBall()
{
	graphics::setOrientation(spinner_angle);
	br.fill_color[0] = 1.1f;
	br.fill_color[1] = 1.1f;
	br.fill_color[2] = 1.1f;
	br.outline_opacity = 0.0f;
	graphics::drawDisk(ball_center_x, ball_center_y, ball_radius, br);
	graphics::resetPose();

}

void Ball::init()
{


	ball_center_x = CANVAS_HEIGHT-50 + rand0to1();
	ball_center_y = CANVAS_HEIGHT-50 + rand0to1();//bgainei apo to kentro kai paei eite pros ta aristera eite pros ta deksia
	ball_direction_x = rand0to1();
	ball_direction_y = rand0to1();
	std::random_device seed;
	std::default_random_engine generator(seed());
	std::uniform_real_distribution<float> distribution(-1.0, 1.0);

	ball_direction_x = distribution(generator);
	ball_direction_y = distribution(generator);



	// Normalize
	float length = std::sqrt(ball_direction_x * ball_direction_x + ball_direction_y * ball_direction_y);
	ball_direction_x /= length;
	ball_direction_y /= length;
}
void Ball::draw()
{
	drawBall();
	drawScore();
}
void Ball::drawScore() 
{

	//char info[40];
	//sprintf_s(info, "(%d,%d)", player1points, player2points);
	//graphics::drawText(CANVAS_WIDTH/2-200, 75, 50, "0", br);
	//graphics::drawText(CANVAS_WIDTH / 2 + 200, 75, 50, "0", br);
}
Ball::Ball()
{
	init();
}
Ball::~Ball()
{

}

