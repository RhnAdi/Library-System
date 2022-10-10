#ifndef TIME_H
#define TIME_H
#include "time.c"

struct Time;

struct Time initTime(
    int day,
    int month,
    int year
);

#endif