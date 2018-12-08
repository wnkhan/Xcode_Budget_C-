//
//  Account.cpp
//  XcodeC++
//
//  Created by William Khan on 6/9/18.
//  Copyright © 2018 William Khan. All rights reserved.
//

#include "Account.hpp"
//#include "AccountConstants.h"

const std::string bill_types[] = {"Utilities", "Cable/Satellite Services","Rent",
                            "Telephone Services","Other Bills","Automotive Expenses"};

const std::string list_types[] = {grocery,bills,pay,dining,gas};

Account::Account(){
    std::vector<Transaction> Grocery;
    std::vector<Transaction> Bills;
    std::vector<Transaction> Pay;
    std::vector<Transaction> Dining;
    std::vector<Transaction> Gas;
    TransactionList[grocery] = Grocery;
    TransactionList[bills] = Bills;
    TransactionList[pay] = Pay;
    TransactionList[dining] = Dining;
    TransactionList[gas] = Gas;
    
}

void Account::AddTransaction(Transaction trans)
{
    if(IsTransactionValidBill(trans.category))
    {
        TransactionList[bills].push_back(trans);
        ListTotals[bills] += trans.amount;
    }
    else if(IsTransactionValid(trans.category))
    {
        TransactionList[trans.category].push_back(trans);
        ListTotals[trans.category] += trans.amount;
    }
    else
    {
        MiscList.push_back(trans);
        miscTotal += trans.amount;
    }
}

void Account::PrintSelectedList(std::string SelectedList)
{
    std::cout << SelectedList << ": " <<ListTotals[SelectedList] << std::endl;
    for (auto listIndex : TransactionList[SelectedList] ) {
        std::cout << listIndex.getTransaction()
                  << std::endl;
    }
    std::cout << std::endl;
}

void Account::PrintAllLists()
{
    for (auto it : TransactionList)
    {
        PrintSelectedList(it.first);
    }
    PrintMiscList();
}

void Account::PrintAcctBal()
{
    for (auto it : ListTotals) {
        accountTotal += it.second;
        std::cout << it.first << " " << it.second << std::endl;
    }
    std::cout << "Misc " << miscTotal << std::endl;
    accountTotal += miscTotal;
    std::cout << "Account Balance: " << accountTotal << std::endl;
}

std::string Account::GetAcctBalOutput()
{
    std::stringstream sstream;
    
    for (auto it : ListTotals) {
        accountTotal += it.second;
        sstream << it.first << " " << it.second << std::endl;
    }
    sstream << "Misc " << miscTotal << std::endl;
    accountTotal += miscTotal;
    sstream << "Account Balance: " << accountTotal << std::endl;
    
    return sstream.str();
}

void Account::PrintListTotals()
{
    for (std::map<std::string,float>::iterator it=ListTotals.begin(); it!=ListTotals.end();it++) {
        std::cout << it->first << " " << it->second << std::endl;
    }
    std::cout << miscTotal << std::endl;
}

void Account::PrintMiscList()
{
    std::cout << "Miscellaneous: " << miscTotal << std::endl;
    for (auto listIndex : MiscList) {
        std::cout << listIndex.getTransaction() << std::endl;
    }
}

std::string Transaction::getTransaction()
{
    return transaction_date.GetDate()
    + " "
    + description
    + " "
    + std::to_string(amount);
}

bool IsTransactionValidBill(std::string category){
    size_t found;
    for (auto index : bill_types) {
        found = category.find(index);
        if(found!=std::string::npos)
            return true;
    }
    return false;
}

bool IsTransactionValid(std::string category){
    size_t found;
    for (auto index : list_types) {
        found = category.find(index);
        if(found!=std::string::npos)
            return true;
    }
    return false;
}
