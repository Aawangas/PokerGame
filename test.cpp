#include<iostream>
#include"card.h"
#include"player.h"
#include"game.h"
int main()
{
    //OrdinaryCard odc{HEART,10};
    //odc.operator<<(std::cout);
    //JokerCard jkc {true};
    //jkc.operator<<(std::cout);
    Game game;
    game.StartGame();
    //game.Display();
    game.Shuffle();
    game.Display();
}