#include "calendar.h"

// PRE: a year greater or equal than 1900
// POST: returns whether that year was a leap year
bool is_leap_year(int year) {
  assert(year >= 1900);
  if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
    return true;
  }
  return false;
}

// PRE: a year greater or equal than 1900
// POST: returns the number of days in that year
int count_days_in_year(int year) {
  assert(year >= 1900);
  if (is_leap_year(year)) {
    return 366;
  } else {
    return 365;
  }
}

// PRE: a month between 1 and 12 and a year greater or equal than 1900
// POST: returns the number of days in the month of that year
int count_days_in_month(int month, int year) {
  assert(month <= 12 && month >= 1 && year >= 1900);
  switch (month){
    case 1: return 31;
    case 2: if (is_leap_year(year)) return 29; else return 28;
    case 3: return 31;
    case 4: return 30;
    case 5: return 31;
    case 6:return 30;
    case 7: return 31;
    case 8: return 31;
    case 9: return 30;
    case 10: return 31;
    case 11: return 30;
    case 12: return 31;
    
    default:
      assert("no valid month input into count_days_in_month()");
      return 0;
  }
}


bool is_valid_february(int year, int day) {
  if (is_leap_year(year)) {
    return (day <= 29);
  } else {
    return (day <= 28);
  }
}


// PRE:  n/a
// POST: returns whether the given values represent a valid date
bool is_valid_date(int day, int month, int year) {
  // higher than reference
  if (year * 10000 + month * 100 + day < 1900 * 10000 + 1 * 100 + 1) {
    return false;
  }
  
  // bigger than 0 days and months
  if (month <= 0 || day <= 0) {
    return false;
  }
  
  // check num of days
  switch (month){
    case 1: return (day <= 31);
    case 2: return is_valid_february(year, day);
    case 3: return (day <= 31);
    case 4: return (day <= 30);
    case 5: return (day <= 31);
    case 6:return (day <= 30);
    case 7: return (day <= 31);
    case 8: return (day <= 31);
    case 9: return (day <= 30);
    case 10: return (day <= 31);
    case 11: return (day <= 30);
    case 12: return (day <= 31);
    
    default:
      return false;
  }
}

// PRE: the given values represent a valid date
// POST: returns the number of days between January 1, 1900 and this date (excluding this date)
int count_days(int day, int month, int year) {
  assert(is_valid_date(day, month, year));
  int days = 0;
  days += day - 1;
  
  for (int i = 1900; i < year; i++) {
    days += count_days_in_year(i);
  }
  for (int i = 1; i < month; i++) {
    days += count_days_in_month(i, year);
  }
  return days;
}

// PRE: the given values represent a (potentially invalid) date
// POST: prints the weekday if the date is valid or "invalid date" otherwise.
//      Everything must be printed in lowercase.
void print_weekday(int day, int month, int year){
  if (is_valid_date(day, month, year)) {
    int weekday = count_days(day, month, year) % 7;
    
    switch (weekday) {
      case 0: std::cout << "monday";
      break;
      case 1: std::cout << "tuesday";
      break;
      case 2: std::cout << "wednesday";
      break;
      case 3: std::cout << "thursday";
      break;
      case 4: std::cout << "friday";
      break;
      case 5: std::cout << "saturday";
      break;
      case 6: std::cout << "sunday";
      break;
      
      default:
        assert("error");
    }
    
  } else {
    std::cout << "invalid date";
  }
}
