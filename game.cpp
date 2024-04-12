#include "game.h"

int randomInt(int min,int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    // 创建分布对象，指定生成整数的范围
    std::uniform_int_distribution<int> dis(min, max);
    // 生成随机整数
    int randomInt = dis(gen);
    return randomInt;
    // 输出随机整数
}

void Game::StartGame()
{
    Card *usedCards[108]{nullptr};
    int usedindex = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            int random_color = randomInt(0, 3);
            int random_num = randomInt(1, 13);
            if ((random_color == 2 && random_num == 13) ||
                (random_color == 3 && random_num == 13))
            {
                j -= 1;
                continue;
            }
            if ((random_color == 0 && random_num == 13) ||
                (random_color == 1 && random_num == 13))
            {
                Card *tempcard = new JokerCard{static_cast<bool>(1 - random_color)};
                int count = 0;
                for (int k = 0; k < usedindex; k++)
                {
                    if (*usedCards[k] == tempcard)
                    {
                        count += 1;
                    }
                }
                delete tempcard;
                if (count >= 2)
                {
                    j -= 1;
                    continue;
                }
                players[i]->addCard(static_cast<bool>(1 - random_color));
                usedCards[usedindex] = new JokerCard{static_cast<bool>(1 - random_color)};
                usedindex += 1;
            }
            else
            {
                Card *tempcard = new OrdinaryCard{static_cast<Color>(random_color), random_num};
                int count = 0;
                for (int k = 0; k < usedindex; k++)
                {
                    if (*usedCards[k] == tempcard)
                    {
                        count += 1;
                    }
                }
                delete tempcard;
                if (count >= 2)
                {
                    j -= 1;
                    continue;
                }
                players[i]->addCard(static_cast<Color>(random_color), random_num);
                usedCards[usedindex] = new OrdinaryCard{static_cast<Color>(random_color), random_num};
                usedindex += 1;
            }
        }
    }
}
void Game::Display()
{
    for(int i = 0;i<4;i++)
    {
        players[i]->display();
    }
}
void Game::Shuffle()
{
    for(int i = 0;i<4;i++)
    {
        players[i]->Shuffle();
    }
}

int Game::Check()
{
    int Num = 0;
    for(int i =0;i<4;i++)
    {
        Num += players[i] ->CheckAce();
    }
    return Num;
}