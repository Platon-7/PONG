#include "game.h"
#include "graphics.h"
#include "config.h"
#include "scancodes.h"

void Game::update()
{
	if (!player_initialized) {//1000 = 1 deyterolepto
		player = new Player();
		player_initialized = true;
	}
	if (!player2_initialized) {//1000 = 1 deyterolepto
		player2 = new Player2();
		player2_initialized = true;
	}

	if (player)
		player->update();

	if (player2)
		player2->update();
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
	graphics::drawRect(CANVAS_WIDTH/2, CANVAS_WIDTH/2, 5, 1000,br);
	//draw player
	if (player)
		player->draw();
	//draw the second player
	if (player2)
		player2->draw();
}

void Game::init()
{
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

}
