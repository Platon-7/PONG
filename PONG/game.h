#pragma once
#include "player.h"
#include "player2.h"
#include "ball.h"
#include "config.h"
class Game 
{
	Player * player = nullptr;
	Player2 * player2 = nullptr;
	bool player_initialized = false;
	bool player2_initialized = false;
	Ball * ball = nullptr;
	int player1points = 0;
	int player2points = 0;
	void spawnBall();
	void checkBall();
public: 
	void update();
	void draw();
	void init();// gia na ksekinhsw ta dedomena, mporei na mhn xreiastei
	Game();// default constructor
	~Game();// default destructor
};// sto telos twn header thelei erwthmatiko