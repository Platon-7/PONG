#pragma once
#include "player.h"
#include "player2.h"
#include "ball.h"
#include "config.h"
class Game 
{
	bool victory_sound = true;
	graphics::Brush br;
	bool end_game = false;
	bool game_has_begun = false;
	bool play_music = true;
	typedef enum{STATUS_START, STATUS_PLAYING, STATUS_EXIT} status_t;//2 katastaseis
	status_t status = STATUS_START;// h metablhth status tha pairnei mia apo tis parapanw
	Player * player = nullptr;
	Player2 * player2 = nullptr;
	bool player_initialized = false;
	bool player2_initialized = false;
	Ball * ball = nullptr;
	int player1points = 0;
	int player2points = 0;
	void spawnBall();
	void checkBall();
	float pad_width = 5;
	bool checkCollision();
	void checkScore();
	void updateStartScreen();
	void updatePlayingScreen();
	void updateEndGame();
	void drawStartScreen();
	void drawPlayingScreen();
	void drawEnd();
public: 
	void update();
	void draw();
	void init();// gia na ksekinhsw ta dedomena, mporei na mhn xreiastei
	Game();// default constructor
	~Game();// default destructor
};// sto telos twn header thelei erwthmatiko