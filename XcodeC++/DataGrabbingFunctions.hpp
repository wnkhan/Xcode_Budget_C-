//
//  DataGrabbingFunctions.hpp
//  XcodeC++
//
//  Created by William Khan on 6/17/18.
//  Copyright © 2018 William Khan. All rights reserved.
//

#ifndef DataGrabbingFunctions_hpp
#define DataGrabbingFunctions_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <regex>
#include "Account.hpp"

std::string ExtractDateString(std::string);
std::string ExtractDescription(std::string);
std::string ExtractCategory(std::string);
float ExtractAmount(std::string);

void ExtractIntgerValuesForDate(std::string, std::vector<int> &date_ints);
Transaction BuildTransaction(std::string data_line);

#endif /* DataGrabbingFunctions_hpp */
