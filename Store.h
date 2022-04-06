//
// Created by colawithsauce on 2022/3/29.
//

#ifndef CLOCK_STORE_H
#define CLOCK_STORE_H

#include "User.h"
#include "common.h"
#include <cstdio>
#include <vector>

struct GoodsItem
{
    int price;
    char comment[COMMENT_WIDTH];
};

enum PurchaseState
{
    SUCCESS,
    NO_SUCH_ITEM,
    ERROR,
};

class Store
{
private:
    std::vector<GoodsItem> goods;

public:
    static Store &getInstance()
    {
        static Store store;
        return store;
    }

    /*
     * Getters, which should all be const functions.
     * */
    void listItems() const;

    /*
     * Consuming functions.
     * */
    void consume(size_t n, User &user);
};

void Store::listItems() const
{
    for (int i = 0; i != goods.size(); i++)
    {
        printf("%d\t%d\t%s", i, goods.at(i).price, goods.at(i).comment);
    }
}

void Store::consume(size_t n, User &user)
{
    if (n >= goods.size())
    {
        printf("NO SUCH ITEM IN STORE!\n");
        return;
    }

    GoodsItem good = goods[n];
    // try to consume this money
    if (user.tryConsume(good.price))
    {
        printf("PURCHASE SUCCESS!\n");
        return;
    }
    printf("ERROR HAPPENED!\n");
}

#endif // CLOCK_STORE_H
