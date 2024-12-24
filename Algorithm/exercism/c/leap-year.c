#include <stdbool.h>

bool leap_year(int year);

bool leap_year(int year)
{
    bool is_leap_year = false;

    if (!(year % 4) && year % 100)
    {
        is_leap_year = true;
    }

    if (!(year % 400))
    {
        is_leap_year = true;
    }

    return is_leap_year;
}