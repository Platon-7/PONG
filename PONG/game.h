#pragma once
#include "player.h"
class Game 
{
	Player * player = nullptr;
public: 
	void update();
	void draw();
	void init();// gia na ksekinhsw ta dedomena, mporei na mhn xreiastei
	Game();// default constructor
	~Game();// default destructor
};// sto telos twn header thelei erwthmatiko