//
// Created by colawithsauce on 2022/3/30.
//

/*
 * This class parse the commands which user input, and transfer the control flow
 * to the accurate class.
 * */

#ifndef CLOCK_COMMANDPARSER_H
#define CLOCK_COMMANDPARSER_H

#include "CountList.h"
#include "Store.h"
#include "TimerList.h"
#include "User.h"

class CommandParser
{
  public:
    static void Parse(char **pString);
};

void CommandParser::Parse(char **pString)
{
    // Parse the pString, and goto the proper place.
}

#endif // CLOCK_COMMANDPARSER_H
