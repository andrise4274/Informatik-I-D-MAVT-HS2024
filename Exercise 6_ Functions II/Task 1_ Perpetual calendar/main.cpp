#include <cassert>
#include <iostream>
#include "calendar.h"

void test_is_leap_year(){
  std::cout << "Year?\n";
  int year; std::cin >> year;
  
  bool ret = is_leap_year(year);
  if (ret)
    std::cout << "This is a leap year" << std::endl;
  else
    std::cout << "This is not a leap year" << std::endl;
}

void test_count_days_in_year(){
  // input the date
  std::cout << "Year?\n";
  int year; std::cin >> year;
  std::cout <<  count_days_in_year(year) << std::endl;
}


void test_count_days_in_month(){
  // input the date
  std::cout << "Month?\n";
  int month; std::cin >> month;

  std::cout << "Year?\n";
  int year; std::cin >> year;
  std::cout <<  count_days_in_month(month, year) << std::endl;
}

void test_is_valid_date(){
  // input the date
  std::cout << "Day?\n";
  int day; std::cin >> day;

  std::cout << "Month?\n";
  int month; std::cin >> month;

  std::cout << "Year?\n";
  int year; std::cin >> year;
  bool ret = is_valid_date(day, month, year);
  if (ret)
    std::cout <<  "This is a valid date" << std::endl;
  else
    std::cout <<  "This is not a valid date" << std::endl;
}


void test_count_days(){
  // input the date
  // std::cout << "Day?\n";
  int day; std::cin >> day;
  
  // std::cout << "Month?\n";
  int month; std::cin >> month;
  
  // std::cout << "Year?\n";
  int year; std::cin >> year;
  std::cout <<  count_days(day, month, year) << std::endl;
}

void test_print_weekday(){
  // input the date
  std::cout << "Day?\n";
  int day; std::cin >> day;

  std::cout << "Month?\n";
  int month; std::cin >> month;

  std::cout << "Year?\n";
  int year; std::cin >> year;
  print_weekday(day, month, year);
}

// Main function of the C++ program.
int main() {
  
  int choice;
  do{
    std::cout << "Please select the function to test:" << std::endl;
    std::cout << "1: is_leap_year" << std::endl;
    std::cout << "2: count_days_in_year" << std::endl;
    std::cout << "3: count_days_in_month" << std::endl;
    std::cout << "4: is_valid_date" << std::endl;
    std::cout << "5: count_days" << std::endl;
    std::cout << "6: print_weekday" << std::endl;
    std::cin >> choice;
  }while(choice < 1 || choice > 7);
    
  //call the appropriate function
  switch(choice){
    case 1:
      test_is_leap_year();
      break;
    case 2:
      test_count_days_in_year();
      break;
    case 3:
      test_count_days_in_month();
      break;
    case 4:
      test_is_valid_date();
      break;
    case 5:
      test_count_days();
      break;
    case 6:
      test_print_weekday();
      break;
  }

  return 0;
}
