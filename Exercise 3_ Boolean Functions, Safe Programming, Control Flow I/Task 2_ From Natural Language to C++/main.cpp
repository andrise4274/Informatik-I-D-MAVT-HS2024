#include<iostream>
#include "solutions.h"
int main() {
  
    unsigned int task;
    unsigned int ua, ub, uc;
    bool ba, bb, bc;
    
    //input task number and data
    std::cin >> task;
    
        
    switch(task){
      case 1:
        std::cin >> ua >> ub;
        std::cout << std::boolalpha << task1(ua, ub) << std::endl;
        break;
      case 2:
        std::cin >> ua;
        std::cout << std::boolalpha << task2(ua) << std::endl;
        break;
      case 3:
        std::cin >> ua >> ub >> uc;
        std::cout << std::boolalpha << task3(ua, ub, uc) << std::endl;
        break;
      case 4:
        std::cin >> std::boolalpha >> ba >> bb >> bc;
        std::cout << std::boolalpha << task4(ba, bb, bc) << std::endl;
        break;
      case 5:
        std::cin >> std::boolalpha >> ba >> std::noboolalpha >> ub;
        std::cout << std::boolalpha << task5(ba, ub) << std::endl;
        break;
      default:
        std::cout << "Task number must be between 1 and 5." << std::endl;
        break;
    }
    return 0;
}