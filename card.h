#ifndef _CARD_H
#define _CARD_H

#include <iostream>

enum Color
{
    HEART,
    SPADE,
    DIAMOND,
    CLUB
};

class Card
{
public:
    virtual std::ostream &operator<<(std::ostream &os) = 0;
    virtual ~Card() {}
    virtual bool operator==(Card *card) = 0;
    virtual int getOrderNum() = 0;
};

class OrdinaryCard : public Card
{
private:
    Color color;
    int num;

public:
    OrdinaryCard(Color cl, int num) : Card(), color(cl), num(num)
    {
    }
    std::ostream &operator<<(std::ostream &os) override
    {
        switch (color)
        {
        case HEART:
            return (os << "红桃" << num << std::endl);
            break;
        case SPADE:
            return (os << "黑桃" << num << std::endl);
            break;
        case DIAMOND:
            return (os << "方片" << num << std::endl);
            break;
        case CLUB:
            return (os << "梅花" << num << std::endl);
            break;
        }
    }
    Color getColor() { return color; }
    int getNumber() { return num; }
    bool operator==(Card *odk) override
    {
        OrdinaryCard *odkptr = dynamic_cast<OrdinaryCard *>(odk);
        if (odkptr)
        {
            if (color == odkptr->getColor() && num == odkptr->getNumber())
            {
                return true;
            }
        }
        return false;
    }
    int getOrderNum() override
    {
        return static_cast<int>(color) * 20 + num;
    }
};

class JokerCard : public Card
{
private:
    bool isRed;

public:
    JokerCard(bool isred) : Card(), isRed(isred)
    {
    }
    bool getisRed() { return isRed; }
    std::ostream &operator<<(std::ostream &os) override
    {
        if (isRed)
            return (os << "大王" << std::endl);
        else
            return (os << "小王" << std::endl);
    }
    bool operator==(Card *jkc) override
    {
        JokerCard *jkcptr = dynamic_cast<JokerCard *>(jkc);
        if (jkcptr)
        {
            if (jkcptr->getisRed() == isRed)
            {
                return true;
            }
        }
        return false;
    }
    int getOrderNum() override
    {
        if (isRed)
        {
            return 201;
        }
        else
        {
            return 200;
        }
    }
};

#endif