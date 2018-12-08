//
//  main.cpp
//  XcodeC++
//
//  Created by William Khan on 6/7/18.
//  Copyright © 2018 William Khan. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "Account.hpp"
#include "AccountConstants.h"
#include "DataGrabber.hpp"
#include "DataGrabbingFunctions.hpp"
#include "DataWriter.hpp"

int main(int argc, const char * argv[]) {
    
    DataGrabber data_object("/Users/williamkhan/Downloads","bk_download.csv");
    
    std::vector<std::string> data;
    data_object.GrabLines(data);
    
    Account checking;
    
    for (auto line : data) {
        if(!line.empty())
        {
            Transaction transObj = BuildTransaction(line);
            checking.AddTransaction(transObj);
        }
    }
    
    DataWriter output_object("/Users/williamkhan/Output","test_file.txt");
    output_object.WriteLine(checking.GetAcctBalOutput());

    
    return 0;
}


