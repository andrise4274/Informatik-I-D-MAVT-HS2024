#pragma once

#include <iostream>
#include <cassert>


// Functions to be implemented

// PRE:  a year greater or equal than 1900
// POST: returns whether that year was a leap year
bool is_leap_year(int year);

// PRE:  a year greater or equal than 1900
// POST: returns the number of days in that year
int count_days_in_year(int year);

// PRE:  a month between 1 and 12 and a year greater or equal than 1900
// POST: returns the number of days in the month of that year
int count_days_in_month(int month, int year);

// PRE:  n/a
// POST: returns whether the given values represent a valid date
bool is_valid_date(int day, int month, int year);

// PRE:  the given values represent a valid date
// POST: returns the number of days between January 1, 1900 and this date (excluding this date)
int count_days(int day, int month, int year);

// PRE: the given values represent a (potentially invalid) date
// POST: prints the weekday if the date is valid or "invalid date" otherwise.
//      Everything must be printed in lowercase.
void print_weekday(int day, int month, int year);