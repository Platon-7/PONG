#pragma once
#include "player.h"
#include "player2.h"
class Game 
{
	Player * player = nullptr;
	Player2 * player2 = nullptr;
	bool player_initialized = false;
	bool player2_initialized = false;
public: 
	void update();
	void draw();
	void init();// gia na ksekinhsw ta dedomena, mporei na mhn xreiastei
	Game();// default constructor
	~Game();// default destructor
};// sto telos twn header thelei erwthmatiko