#include "game.h"
#include "graphics.h"
#include "config.h"

void Game::update()
{
	if (graphics::getGlobalTime() > 2000) {
		player = new Player();
	}

	if (player)
		player->update();
}

void Game::draw()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "OSFP.png";// to kanw convert apo c string se c++ string
	br.outline_opacity = 0.0f;// sbinei thn asprh grammh sto perigramma
	
	//float offset = CANVAS_HEIGHT * sinf(graphics::getGlobalTime()/1000.0f)/4;//to bazw se sinimitono gia na palindromei kai na mh fugei h eikona kai den ksanagirisei
	
	//draw background

	graphics::drawRect(CANVAS_WIDTH/2,CANVAS_HEIGHT/2,CANVAS_WIDTH,CANVAS_WIDTH ,br);//	graphics::drawRect (float center_x, float center_y, float width, float height, const Brush &brush)
	//bazw ksana CANVAS_WIDTH sto 4o orisma gia na mhn prosarmozw thn eikona sta thelw moy alla na thn afhnw, akoma kai na ksefigei apo th xwrhtikothta toy tamplo, an thelo na to prosarmosw bazw CANVAS_HEIGHT
	
	//draw player
	if (player)
		player->draw();
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

}
