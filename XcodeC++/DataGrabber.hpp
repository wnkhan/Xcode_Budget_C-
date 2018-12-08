//
//  DataGrabber.hpp
//  XcodeC++
//
//  Created by William Khan on 6/16/18.
//  Copyright © 2018 William Khan. All rights reserved.
//

#ifndef DataGrabber_hpp
#define DataGrabber_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class DataGrabber{
private:
    std::ifstream input_file;
    std::string file_name;
    std::string file_path;
    
public:
    DataGrabber(std::string path,std::string file_name);
    ~DataGrabber();
    std::string GrabLine();
    void GrabLines(std::vector<std::string> &data);
};

#endif /* DataGrabber_hpp */
