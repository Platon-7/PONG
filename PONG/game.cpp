#include "game.h"
#include "graphics.h"
#include "config.h"
#include <vecmath.h>
#include "ball.h"
#include <math.h>



void Game::spawnBall()
{
	if (!ball) {
		ball = new Ball(*this);
	}
}
void Game::checkBall()
{
	if (!ball->ballActive()) {
		delete ball;
		ball = nullptr;
	}
}
void Game::checkScore()
{
	if (ball) {
		if (ball->getPosX() >= CANVAS_WIDTH) {
			player1points += 1;
			std::string wav = std::string(ASSET_PATH) + "point.wav";
			graphics::playSound(wav, 0.5f);

		}
		if (ball->getPosX() <= 0) {
			player2points += 1;
			std::string wav = std::string(ASSET_PATH) + "point.wav";
			graphics::playSound(wav, 0.5f);
		}
	}
}

bool Game::checkCollision()
{
	Rectangle r1 = player->getCollisionRect();
	Rectangle r2 = player2->getCollisionRect();
	Disk d1 = ball->getCollisionHull();

	/*ta previous

	float prev_testX1 = x;
	float prev_testY1 = y;*/

	// ta current


	// first player previous

	/*if (x < r1.rx) {
		prev_testX1 = r1.rx-r1.rw/2;
	}
	else if (x > r1.rx - r1.rw/2 + r1.rw ) {
		prev_testX1 = r1.rx -r1.rw/2 + r1.rw;
	}
	if (y < prev_player_y - r1.rh/2)
		prev_testY1 = prev_player_y - r1.rh/2;
	else if (y > prev_player_y + r1.rh/2)
		prev_testY1 = prev_player_y + r1.rh/2;
		
	float prev_distX1 = x - prev_testX1;
	float prev_distY1 = y - prev_testY1;
	float prev_distance = sqrt((prev_distX1 * prev_distX1) + (prev_distY1 * prev_distY1));*/

	// first player current

	float testX1 = d1.cx;
	float testY1 = d1.cy;
	float rectangle_x = r1.rx - r1.rw / 2;
	float rectangle_y = r1.ry - r1.rh / 2;

	if (d1.cx < rectangle_x) 
		testX1 = rectangle_x; //if ball is left
	else if (d1.cx > rectangle_x + r1.rw)
		testX1 = rectangle_x + r1.rw; //if ball is right
	if (d1.cy < rectangle_y)
		testY1 = rectangle_y;//if ball is above
	else if (d1.cy > rectangle_y + r1.rh)
		testY1 =  rectangle_y + r1.rh;// if ball is below


	float distX1 = d1.cx - testX1;
	float distY1 = d1.cy - testY1;
	float distance1 = sqrt((distX1 * distX1) + (distY1 * distY1));

	//current gia ton deytero paikth

	float testX2 = d1.cx;
	float testY2 = d1.cy;
	float rectangle_x_beta = r2.rx - r2.rw / 2;
	float rectangle_y_beta = r2.ry - r2.rh / 2;


	if (d1.cx < rectangle_x_beta)
		testX2 = rectangle_x_beta; //if ball is left
	else if (d1.cx > rectangle_x_beta + r2.rw)
		testX2 = rectangle_x_beta + r2.rw; //if ball is right
	if (d1.cy < rectangle_y_beta)
		testY2 = rectangle_y_beta;//if ball is above
	else if (d1.cy > rectangle_y_beta + r2.rh)
		testY2 = rectangle_y_beta + r2.rh;// if ball is below

	float distX2 = d1.cx - testX2;
	float distY2 = d1.cy - testY2;
	float distance2 = sqrt((distX2 * distX2) + (distY2 * distY2));


	if (distance1 <= d1.radius) {
		return true;
	}
	else if (distance2 <= d1.radius)
		return true;
	/*else if (prev_distance <= d1.radius && prev_distance>=d1.radius/2){
			return true;
		}*/
	else {
		return false;
	}

}

void Game::update()
{
	if (!player_initialized)
	{
		player = new Player(*this);
		player_initialized = true;
	}
	if (!player2_initialized)
	{
		player2 = new Player2(*this);
		player2_initialized = true;
	}
	if (player)
		player->update();

	/*float prev_player_y = player->getPlayerPosY();//***an player=nullptr tha skasei*/
	if (player2)
		player2->update();

	//checkBall();

	spawnBall();

	/*if (ball) {
		float prev_x = ball->getPosX();
		float prev_y = ball->getPosY();
		ball->update();

		float cur_x = ball->getPosX();
		float cur_y = ball->getPosY();
		float dx = cur_x - prev_x;
		float dy = cur_y - prev_y;

		float len = dx * dx + dy * dy;
		int N_tests = 5;
		for (int i = 0; i < N_tests; i++) {
			float s = (i + 0.5) / N_tests;
			float x = s * (cur_x - prev_x) + prev_x;
			float y = s * (cur_y - prev_y) + prev_y;
			if (checkCollision()) {
				ball->hit();
			}

		}



	}*/
	if (ball) {
		ball->update();
	}
	if (checkCollision()) {
		ball->hit();
	}
	int temp_player_1_points = player1points;
	int temp_player_2_points = player2points;
	checkScore();
	if (player1points != temp_player_1_points || player2points != temp_player_2_points) {
		delete ball;
		ball = nullptr;

	}

}
void Game::draw()
{

	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "pong_background.png";// to kanw convert apo c string se c++ string
	//br.outline_opacity = 0.0f;// sbinei thn asprh grammh sto perigramma

	//float offset = CANVAS_HEIGHT * sinf(graphics::getGlobalTime()/1000.0f)/4;//to bazw se sinimitono gia na palindromei kai na mh fugei h eikona kai den ksanagirisei

	//draw background

	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_WIDTH, br);//	graphics::drawRect (float center_x, float center_y, float width, float height, const Brush &brush)
	//bazw ksana CANVAS_WIDTH sto 4o orisma gia na mhn prosarmozw thn eikona sta thelw moy alla na thn afhnw, akoma kai na ksefigei apo th xwrhtikothta toy tamplo, an thelo na to prosarmosw bazw CANVAS_HEIGHT

	br.texture = "";
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_WIDTH / 2, 5, 1000, br);
	//draw player
	if (player)
		player->draw();
	//draw the second player
	if (player2)
		player2->draw();

	if (ball)
		ball->draw();
	if (player)
	{
		char info[10];
		char info_beta[10];
		sprintf_s(info, "%d", player1points);
		sprintf_s(info_beta, "%d", player2points);
		graphics::drawText(CANVAS_WIDTH / 2 - 200, 100, 100, info, br);
		graphics::drawText(CANVAS_WIDTH / 2 + 200, 100, 100, info_beta, br);
	}

}
void Game::init()
{
	graphics::setFont(std::string(ASSET_PATH) + "Pong.otf");
}

Game::Game()
{
}

Game::~Game()
{// thimisoy, molis ftiakseis enan player prepei na ton katastrepseis kiolas
	if (player) {
		delete player;
	}
	if (player2) {
		delete player2;
	}
	if (ball) {
		delete ball;
	}

}

/*
	Rectangle r1 = player->getCollisionRect();
	//Line r2 = player2->getCollisionLine();
	Disk d1 = ball->getCollisionHull();
	//ta previous
	float prev_testX1 = x;
	float prev_testY1 = y;
	// ta current
	float testX1 = d1.cx;
	float testY1 = d1.cy;
	// first player previous
	if (x < r1.rx) {
		prev_testX1 = r1.rx;
	}
	else if (x > r1.rx + r1.rw) {
		prev_testX1 = r1.rx + r1.rw;
	}
	if (y < prev_player_y)
		prev_testY1 = prev_player_y;
	else if (y > prev_player_y + r1.rh)
		prev_testY1 = prev_player_y + r1.rh;
	// first player current
	if (d1.cx < r1.rx) {
		testX1 = r1.rx;
	}//if ball is left
	else if (d1.cx > r1.rx + r1.rw){
		testX1 = r1.rx + r1.rw;
		}//if ball is right
	if (d1.cy < r1.ry)
		testY1 = r1.ry;//if ball is above
	else if (d1.cy > r1.ry + r1.rh)
		testY1 =  r1.ry + r1.rh;// if ball is below

	//previous
	float prev_distX1 = x - prev_testX1;
	float prev_distY1 = y - prev_testY1;
	float prev_distance = sqrt((prev_distX1 * prev_distX1) + (prev_distY1 * prev_distY1));
	//current
	float distX1 = d1.cx - testX1;
	float distY1 = d1.cy - testY1;
	float distance1 = sqrt((distX1 * distX1) + (distY1 * distY1));


	if (distance1 <= d1.radius) {
		return true;
	}else if (prev_distance <= d1.radius && prev_distance>=d1.radius/2){
			return true;
		}
	else {
		return false;
	}*/