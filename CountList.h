//
// Created by colawithsauce on 2022/3/29.
//

// TODO: 将这两个类使用模版改写

#ifndef CLOCK_COUNTLIST_H
#define CLOCK_COUNTLIST_H

#include "User.h"
#include "common.h"
#include <cstdio>
#include <cstring>
#include <vector>

// 单个计时项目的倍率与累积次数
struct CountItem
{
    int mag;                       // magnification 倍率
    int count;                     // 累计的次数
    char comment[COMMENT_WIDTH]{}; // 本条项目的内容(暂不支持UTF-8)

    CountItem(int mag, const char *comment) : mag(mag)
    {
        strncpy(this->comment, comment, COMMENT_WIDTH);
        count = 0;
    }
};

class CountList
{
private:
    std::vector<CountItem> items;

    CountList()
    {
        items = std::vector<CountItem>();
#ifdef DEBUG
        items.emplace_back(CountItem(5, "Brake before get trapped!"));
        items.emplace_back(CountItem(1, "Stop after get trapped!"));
#endif
    }

public:
    static CountList &getInstance()
    {
        static CountList countList;
        return countList;
    }

    void listItems() const;

    void addItem(char *comment, int mag);

    void updateItem(size_t n, char *comment, int mag);

    void actionItem(size_t n, User &user);
};

void CountList::listItems() const
{
    for (int i = 0; i != items.size(); ++i)
    {
        printf("%d\t%s\t%d\t%d\n", i, items[i].comment, items[i].mag,
               items[i].count);
    }
}

void CountList::addItem(char *comment, int mag)
{
    CountItem item(mag, comment);

    items.push_back(item);
}

void CountList::updateItem(size_t n, char *comment, int mag)
{
    items.at(n).mag = mag;
    strncpy(items.at(n).comment, comment, COMMENT_WIDTH);
}

void CountList::actionItem(size_t n, User &user)
{
    user.tryAdd(items[n].mag);
}

#endif // CLOCK_COUNTLIST_H
