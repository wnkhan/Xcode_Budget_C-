//
//  Transaction.hpp
//  XcodeC++
//
//  Created by William Khan on 6/9/18.
//  Copyright © 2018 William Khan. All rights reserved.
//

#ifndef Transaction_hpp
#define Transaction_hpp

#include <stdio.h>
#include <string>

class Transaction{
private:
    float amount = 0;
    std::string category;
    std::string description;
public:
    Transaction(float amount):amount(amount){};
    Transaction(float amount, std::string category, std::string description):amount(amount),category(category),description(description){};

};

#endif /* Transaction_hpp */
