//
//  Date.cpp
//  XcodeC++
//
//  Created by William Khan on 6/15/18.
//  Copyright © 2018 William Khan. All rights reserved.
//

#include "Date.hpp"
#include <iostream>


void Date::PrintDate(){
    std::cout << GetMonthString() << " " << day << ", " << year << std::endl;
}
std::string Date::GetDate(){
    std::string date_string;
    date_string = GetMonthString() + " " + std::to_string(day) + ", " + std::to_string(year);
    return date_string;
}

int Date::GetMonth(){return month;}
int Date::GetDay(){return day;};
int Date::GetYear(){return year;}

std::string Date::GetMonthString(){
    switch(month){
        case 1: return "January";
            break;
        case 2: return "February";
            break;
        case 3: return "March";
            break;
        case 4: return "April";
            break;
        case 5: return "May";
            break;
        case 6: return "June";
            break;
        case 7: return "July";
            break;
        case 8: return "August";
            break;
        case 9: return "September";
            break;
        case 10: return "October";
            break;
        case 11: return "November";
            break;
        case 12: return "December";
            break;
        default: return "Invalid Month";
            break;
    }
}
