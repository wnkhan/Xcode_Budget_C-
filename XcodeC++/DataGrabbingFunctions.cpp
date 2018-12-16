//
//  DataGrabbingFunctions.cpp
//  XcodeC++
//
//  Created by William Khan on 6/17/18.
//  Copyright © 2018 William Khan. All rights reserved.
//

#include "DataGrabbingFunctions.hpp"

std::string ExtractDateString(std::string raw_data)
{
    std::regex date("\\d\\d(/)\\d\\d(/)\\d\\d\\d\\d");
    std::smatch Date;
    regex_search(raw_data,Date,date);
    return Date.str();
}

std::string ExtractDescription(std::string raw_data)
{
    size_t firstIndex = raw_data.find(",,");
    size_t startIndex = raw_data.find(",,",firstIndex+2);
    size_t endIndex = raw_data.find(",",startIndex+2);
    size_t diff = endIndex - startIndex;
    std::string description = raw_data.substr(startIndex+2,diff-2);
    return description;
}

std::string ExtractCategory(std::string raw_data)
{
    size_t first = raw_data.find(",,");
    size_t second = raw_data.find(",,",first+2);
    size_t startIndex = raw_data.find(",", second+2);
    size_t endIndex = raw_data.find(",",startIndex+1);
    size_t diff = endIndex - startIndex;
    std::string category = raw_data.substr(startIndex+1,diff-1);
    return category;
}

float ExtractAmount(std::string raw_data)
{
    std::regex amount("-(//d|.)+");
    std::smatch Amount;
    regex_search(raw_data,Amount,amount);
    std::string string_copy = Amount.str();
    
    std::regex positive("[^--](//d |.)+");
    std::smatch Modified;
    std::string amount_str = regex_search(string_copy,Modified,positive) ? Modified.str() : Amount.str();
    
    try{
        stof(amount_str);
    }
    catch(const std::invalid_argument &ia){
        std::cerr  << "Inavlid Argument " << ia.what() << " " << amount_str << std::endl;
        return 0.0;
    }
    std::cout << amount_str << std::endl;
    return stof(amount_str);
}

void ExtractIntgerValuesForDate(std::string date, std::vector<int> &date_ints)
{
    size_t firstDateSep = date.find("/");
    size_t secondDateSep = date.find("/",firstDateSep+1);
    size_t diff = secondDateSep - firstDateSep;
    
    std::string month = date.substr(0,firstDateSep);
    std::string day = date.substr(firstDateSep+1,diff-1);
    std::string year = date.substr(secondDateSep+1);
    
    date_ints.push_back(stoi(month));
    date_ints.push_back(stoi(day));
    date_ints.push_back(stoi(year));
}

Transaction BuildTransaction(std::string data_line)
{
    std::string date = ExtractDateString(data_line);
    std::vector<int> date_ints;
    ExtractIntgerValuesForDate(date, date_ints);
    std::string category = ExtractCategory(data_line);
    std::string description = ExtractDescription(data_line);
    float amount = ExtractAmount(data_line);
    
    Transaction tobject(amount,description,category,
                        date_ints[0],date_ints[1],date_ints[2]);
    
    return tobject;
}





