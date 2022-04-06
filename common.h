//
// Created by colawithsauce on 4/1/22.
//

#ifndef SUBSCRIBINGSIMULATOR_COMMON_H
#define SUBSCRIBINGSIMULATOR_COMMON_H

#include <algorithm>
#define DEBUG
static const int COMMENT_WIDTH = 128;

const char HELP_STRING[] = "* Usage: Module Action Arguments\n\
* examples:\n\
*   store buy 1\n\
*   timer add 1 1000 (by seconds)\n\
*   counter add 1\n\
";

bool is_number(const std::string &s)
{
    return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char c) {
                             return !std::isdigit(c);
                         }) == s.end();
}

#endif // SUBSCRIBINGSIMULATOR_COMMON_H
