//
// Created by colawithsauce on 2022/3/29.
//

#ifndef CLOCK_USER_H
#define CLOCK_USER_H
#include "ErrorMessage.h"
#include <memory>
#include <string>

class User
{
private:
    int _coin;
    User()
    {
        _coin = 114514;
    }

public:
    using Ptr = std::shared_ptr<User>;

    static User &getInstance()
    {
        static thread_local User user;
        return user;
    }

    int getCoin() const;

    void printCoins() const
    {
        printf("There are %d coins in your account now!\n", getCoin());
    }

    // 通过各种手段增加金币
    // try to add coin to account. if success return true, else return false;
    bool tryAdd(int coin);

    // 花费金币
    inline bool can_consume(int cost) const
    {
        return _coin >= cost;
    }

    // if can pay, then pay and return true; else return false;
    bool tryConsume(int cost);
};

int User::getCoin() const
{
    return _coin;
}

bool User::tryConsume(int cost)
{
    if (can_consume(cost))
    {
        _coin -= cost;
        return true;
    }
    else
    {
        clws::errorMessage = "No enough money!";
        return false;
    }
}

bool User::tryAdd(int coin)
{
    _coin += coin;

    // At current implement, always will success.
    return true;
}

#endif // CLOCK_USER_H
