#ifndef _GAME_H
#define _GAME_H
#include"player.h"
#include <random>

class Game
{
    private:
    Player* players[4];
    public:
    Game()
    {
        players[0] = new Player{"A"};
        players[1] = new Player{"B"};
        players[2] = new Player{"C"};
        players[3] = new Player{"D"};
    }
    ~Game()
    {
        for(int i = 0;i<4;i++)
        {
            if(players[i])
            delete players[i];
        }
    }

    void StartGame();
    void Display();
    void Shuffle();
    int Check();

};




#endif