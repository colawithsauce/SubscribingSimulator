//
// Created by colawithsauce on 4/1/22.
//

/*
 * This factory get user input, and product the actions. And the actions should
 * be "runnable", so that we can just use:
 * `Action action = ActionFactory.produce(user_input); actionItem.run();`
 * to run us functions.
 * */

#ifndef SUBSCRIBINGSIMULATOR_ACTIONFACTORY_H
#define SUBSCRIBINGSIMULATOR_ACTIONFACTORY_H

#include "CountList.h"
#include "Store.h"
#include "TimerList.h"
#include "User.h"
#include "common.h"
#include <sstream>
#include <string>
#include <utility>

class Action
{
public:
    using Ptr = std::shared_ptr<Action>;
    virtual void run() = 0;
};

class TimerAddAction : public Action
{
private:
    size_t position;
    int seconds;

public:
    TimerAddAction(size_t position, int seconds)
        : position(position), seconds(seconds)
    {
    }
    void run() override
    {
        TimerList::getInstance().addTime(seconds, position,
                                         User::getInstance());
        User::getInstance().printCoins();
    }
};

class TimerListAction : public Action
{
    void run() override
    {
        TimerList timerList = TimerList::getInstance();
        timerList.listItems();
    }
};

class CountListAction : public Action
{
public:
    void run() override
    {
        CountList::getInstance().listItems();
    }
};

class CountAddAction : public Action
{
private:
    size_t position;

public:
    explicit CountAddAction(size_t position) : position(position)
    {
    }
    void run() override
    {
        CountList::getInstance().actionItem(position, User::getInstance());
        User::getInstance().printCoins();
    }
};

class StoreListAction : public Action
{
public:
    void run() override
    {
        Store::getInstance().listItems();
    }
};
class StoreConsumeAction : public Action
{
private:
    size_t position;

public:
    explicit StoreConsumeAction(size_t position) : position(position)
    {
    }
    void run() override
    {
        Store::getInstance().consume(position, User::getInstance());
        User::getInstance().printCoins();
    }
};

class PrintHelpAction : public Action
{
public:
    void run() override
    {
        printf(HELP_STRING);
        User::getInstance().printCoins();
    }
};

class ActionFactory
{
public:
    static Action::Ptr produce(const std::string &user_input);

private:
    User::Ptr user;
};

/*
 * Usage: Module Action Arguments
 * examples:
 *   store buy 1
 *   timer add 1 1000 (by seconds)
 *   counter add 1
 */
Action::Ptr ActionFactory::produce(const std::string &user_input)
{
    std::vector<std::string> argv;
    std::string temp;
    std::stringstream ss(user_input);
    while (std::getline(ss, temp, ' '))
    {
        if (!temp.empty())
            argv.push_back(temp);
    }
#ifdef DEBUG
    printf("current args: %s %s\n", argv[0].c_str(), argv[1].c_str());
#endif

    // The first argument
    if (argv[0] == "store")
    {
        if (argv[1] == "buy")
        {
            if (is_number(argv[2]))
            {
                return std::make_shared<StoreConsumeAction>(std::stoi(argv[2]));
            }
        }
        else if (argv[1] == "list")
        {
#ifdef DEBUG
            printf("printing store things\n");
#endif
            return std::make_shared<StoreListAction>();
        }
    }
    else if (argv[0] == "timer")
    {
        if (argv[1] == "add")
        {
            if (is_number(argv[2]) && is_number(argv[3]))
            {
                return std::make_shared<TimerAddAction>(stoi(argv[2]),
                                                        stoi(argv[3]));
            }
        }
        else if (argv[1] == "list")
        {
            return std::make_shared<TimerListAction>();
        }
        perror("Syntax Error: timer add [position] [seconds]");
    }
    else if (argv[0] == "counter")
    {
        if (argv[1] == "list")
        {
            return std::make_shared<CountListAction>();
        }
        else if (argv[1] == "add")
        {
            if (is_number(argv[2]))
            {
                return std::make_shared<CountAddAction>(stoi(argv[2]));
            }
        }
    }
    return std::make_shared<PrintHelpAction>();
}

#endif // SUBSCRIBINGSIMULATOR_ACTIONFACTORY_H
