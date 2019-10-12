#pragma once
#include <cstdio>
#define DEBUG_MODE
#ifdef DEBUG_MODE
#define ASSERT(condition, message) \
if(!(condition)){\
std::perror(message);\
std::abort();\
}
#else
#define ASSERT(condition, message)
//
#endif