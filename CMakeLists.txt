cmake_minimum_required(VERSION 3.21)
project(SubscribingSimulator)

set(CMAKE_CXX_STANDARD 14)

add_executable(SubscribingSimulator main.cpp Timer.h User.h Store.h TimerList.h CountList.h CommandParser.h ErrorMessage.h ActionFactory.h Singleton.h common.h)
