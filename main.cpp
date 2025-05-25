#include "Field.cpp"
#include "Game.cpp"
#include "ColorEnum.h"

int main(int argc, char **argv)
{
    Field field; 
    Game game;
    game.playGame(field);

    return 0;
}