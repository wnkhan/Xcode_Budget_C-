//
//  Account.hpp
//  XcodeC++
//
//  Created by William Khan on 6/9/18.
//  Copyright © 2018 William Khan. All rights reserved.
//

#ifndef Account_hpp
#define Account_hpp
#include "Date.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include "AccountConstants.h"


const std::string grocery = "Groceries", bills = "Bills", pay = "Paychecks/Salary",
                  dining = "Restaurants/Dining", gas = "Gasoline/Fuel";


struct Transaction{
    float amount = 0;
    std::string description;
    std::string category;
    Date transaction_date;
    
   
    Transaction(float a, std::string d, std::string c, int month, int day, int year)
                :amount(a),description(d),category(c),transaction_date(month,day,year){};
    
    std::string getTransaction();
};

class Account{
private:
    float accountTotal = 0;
    float miscTotal = 0;
    std::map<std::string,float> ListTotals = {{grocery,0},{bills,0},{pay,0},
                                              {dining,0},{gas,0}};
    std::map<std::string,std::vector<Transaction>> TransactionList;
    std::vector<Transaction> MiscList;
    
public:
    Account();
    void AddTransaction(Transaction);
    void PrintSelectedList(std::string);
    void PrintAllLists();
    void PrintAcctBal();
    std::string GetAcctBalOutput();
    void PrintListTotals();
    void PrintMiscList();
};

bool IsTransactionValidBill(std::string category);
bool IsTransactionValid(std::string category);

#endif /* Account_hpp */
