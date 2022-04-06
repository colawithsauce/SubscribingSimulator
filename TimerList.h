//
// Created by colawithsauce on 2022/3/29.
//

// TODO: 将这两个类使用模版改写

#ifndef CLOCK_TIMERLIST_H
#define CLOCK_TIMERLIST_H

//#include "Timer.h"
#include "Singleton.h"
#include "User.h"
#include "common.h"
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

// 单个计时项目的倍率与累积时间
struct TimerItem
{
    int mag;                       // magnification 倍率
    int seconds;                   // 累计的时间
    char comment[COMMENT_WIDTH]{}; // 本条项目的内容(暂不支持UTF-8)

    TimerItem(int mag, const char *comment) : mag(mag)
    {
        strncpy(this->comment, comment, COMMENT_WIDTH);
        seconds = 0;
    }
};

class TimerList
{
private:
    std::vector<TimerItem> items;

    TimerList()
    {
        items = std::vector<TimerItem>();
#ifdef DEBUG
        items.emplace_back(TimerItem(1, "Hello"));
        items.emplace_back(TimerItem(2, "World!"));
#endif
    }

public:
    // Return the reference to the only instance.
    static TimerList &getInstance()
    {
        static TimerList timerList;
        return timerList;
    }

    void listItems() const;

    void addItem(char *comment, int mag);

    void updateItem(size_t n, char *comment, int mag);

    void addTime(int seconds, size_t n, User &user);

    // TODO: 实现这个方法
    void startTimer(TimerItem *item, User &user);
};

void TimerList::listItems() const
{
    for (int i = 0; i != items.size(); ++i)
    {
        printf("%d\t%s\t%d\t%d\n", i, items[i].comment, items[i].mag,
               items[i].seconds);
    }
}

void TimerList::addItem(char *comment, int mag)
{
    TimerItem item(mag, comment);
    items.push_back(item);
}

void TimerList::updateItem(size_t n, char *comment, int mag)
{
    items.at(n).mag = mag;
    strncpy(items.at(n).comment, comment, COMMENT_WIDTH);
}

/*
 * Add certain time into the list, and add certain coin into the User's
 * account.
 * */
void TimerList::addTime(int seconds, size_t n, User &user)
{
    items[n].seconds += seconds;
    user.tryAdd(seconds * items[n].mag);
}

void TimerList::startTimer(TimerItem *item, User &user)
{
    // TODO: Start timer.
    //    clws::Timer timer;
}

#endif // CLOCK_TIMERLIST_H
