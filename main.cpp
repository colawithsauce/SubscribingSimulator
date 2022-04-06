#include "ActionFactory.h"
#include "CommandParser.h"
#include "Timer.h"
#include "common.h"
#include <iostream>

/*
 * This program provides a Timer, that can have some comment, and can
 * pauseOrResume and break.
 */

int main()
{
    std::string user_input;
    while (user_input != "exit")
    {
        getline(std::cin, user_input);
        Action::Ptr paction = ActionFactory::produce(user_input);

        paction->run();
    }

    return 0;
}
