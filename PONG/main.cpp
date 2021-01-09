#include "graphics.h"
#include "game.h"
#include "config.h"
#include "vecmath.h"


// The custom callback function that the library calls 
// to check for and set the current application state.
void update(float ms)
{
    Game* game = reinterpret_cast<Game*>(graphics::getUserData());// prepei na kanw cast gt sigkrinw Game me Void, ayto einai to stigmiotypo
    //kanonika tha eprepe na tsekarw an einai null pointer alla den xreiazetai gt ksero oti den einai, katw kanw setUserData akribws prin kalesw thn update

    game->update();
}


// The window content drawing function.
void draw()
{
    Game* game = reinterpret_cast<Game*>(graphics::getUserData());
    game->draw();
}


int main()
{
    Game mygame;// arxikopoiw ton constructor
    graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "PONG");


    graphics::setUserData(&mygame);

    graphics::setDrawFunction(draw);

    graphics::setUpdateFunction(update);

    graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);


    mygame.init();//an thelw
    graphics::startMessageLoop();
    //graphics::destroyWindow();

}
