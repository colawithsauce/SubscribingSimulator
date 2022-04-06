//
// Created by colawithsauce on 2022/3/28.
//
//

/*
 * 这个类的功能是，每次调用读取函数的时候就会将时间读取出来。
 * 支持暂停功能。
 */

#ifndef CLOCK_TIMER_H
#define CLOCK_TIMER_H
#include <string>

namespace clws
{
class Timer
{
private:
    int _seconds = 0; // seconds elapsed
    bool paused = true;

private:
    //    the Timer tick function, should be executed every 1 second.
    void tick();

public:
    /* These function give the access to the Timer's tick. Includes start,
     * stop, pauseOrResume, and tick. */
    //    Start on initialized
    Timer()
    {
        paused = false;
    }

    //    this function stop this Timer.
    void stop();

    //    this function pauseOrResume this Timer.
    void pauseOrResume();

    /* The following functions give us the access the data to the Timer's
     * function, in that these functions should be const! */

    //    Get how many seconds remain in this Timer.
    int getSeconds() const;

    // Get the hh:mm:ss style string.

    //    Get if this Timer paused.
    bool getPaused() const;
};

void Timer::tick()
{
    if (!paused)
    {
        _seconds += 1;
    }
}

void Timer::stop()
{
    paused = true;
}

void Timer::pauseOrResume()
{
    paused = !paused;
}

int Timer::getSeconds() const
{
    return this->_seconds;
}

bool Timer::getPaused() const
{
    return paused;
}
} // namespace clws

#endif // CLOCK_TIMER_H
