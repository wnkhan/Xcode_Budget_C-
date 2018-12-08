//
//  DataWriter.hpp
//  XcodeC++
//
//  Created by William Khan on 11/6/18.
//  Copyright © 2018 William Khan. All rights reserved.
//

#ifndef DataWriter_hpp
#define DataWriter_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class DataWriter{
private:
    std::ofstream output_file;
    std::string file_name;
    std::string file_path;
    
public:
     DataWriter(std::string path,std::string file_name);
    ~DataWriter();
    void WriteLine(const std::string &line);
    void WriteNewLine();
    void WriteLines(std::vector<std::string> &data);
};

#endif /* DataWriter_hpp */
