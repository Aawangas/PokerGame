#include"player.h"

void Player::addCard(Color cl,int num)
{
    cards[index] = new OrdinaryCard{cl,num};
    index += 1;
    
}

void Player::addCard(bool isred)
{
    cards[index] = new JokerCard {isred};
    index += 1;
}


void swap(Card*&a, Card*& b) {
    Card* temp = a;
    a = b;
    b = temp;
}

void Player::Shuffle()
{
    for(int i = 0;i<24;i++)
    {
        for(int j = 0;j<25-i-1;j++)
        {
            if(cards[j]->getOrderNum() < cards[j+1]->getOrderNum())
            {
                swap(cards[j],cards[j+1]);
            }
        }
    }
}



// 冒泡排序函数

