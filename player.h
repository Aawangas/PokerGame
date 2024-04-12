#ifndef _PLAYER_H
#define _PLAYER_H

#include "card.h"
#include <iostream>
class Player
{
private:
    std::string name;
    Card *cards[25]{nullptr};
    int index{0};

public:
    Player(std::string name) : name(name)
    {
    }
    void addCard(Color cl, int num);
    void addCard(bool isred);
    ~Player()
    {
        for (int i = 0; i < index; i++)
        {
            if (cards[i])
                delete cards[i];
        }
    }
    void display()
    {
        std::cout << "DISPLAY " << name << std::endl;
        for (int i = 0; i < index; i++)
        {
            if (cards[i])
            {
                cards[i]->operator<<(std::cout);
            }
        }
    }
    void Shuffle();
    int CheckAce()
    {
        int A1 = 0;
        int A2 = 0;
        int A3 = 0;
        int A4 = 0;
        for (int i = 0; i < index; i++)
        {
            Card *Ace1 = new OrdinaryCard{HEART, 1};
            if (*cards[i] == (Ace1))
            {
                A1 += 1;
            }
            Card *Ace2 = new OrdinaryCard{SPADE, 1};
            if (*cards[i] == (Ace2))
            {
                A2 += 1;
            }
            Card *Ace3 = new OrdinaryCard{DIAMOND, 1};
            if (*cards[i] == (Ace3))
            {
                A3 += 1;
            }
            Card *Ace4 = new OrdinaryCard{CLUB, 1};
            if (*cards[i] == (Ace4))
            {
                A4 += 1;
            }
            delete Ace1;
            delete Ace2;
            delete Ace3;
            delete Ace4;
        }
        return A1/2+A2/2+A3/2+A4/2;
    }
};

#endif