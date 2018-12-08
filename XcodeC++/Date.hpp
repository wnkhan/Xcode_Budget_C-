//
//  Date.hpp
//  XcodeC++
//
//  Created by William Khan on 6/15/18.
//  Copyright © 2018 William Khan. All rights reserved.
//

#ifndef Date_hpp
#define Date_hpp

#include <stdio.h>
#include <string>

class Date{
private:
    int month;
    int day;
    int year;
public:
    //constructor
    Date(int month,int day, int year):month(month),day(day),year(year){};
    
    void PrintDate();
    std::string GetDate();
    int GetMonth();
    int GetDay();
    int GetYear();
    std::string GetMonthString();
};


#endif /* Date_hpp */
