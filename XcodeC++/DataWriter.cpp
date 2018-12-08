//
//  DataWriter.cpp
//  XcodeC++
//
//  Created by William Khan on 11/6/18.
//  Copyright © 2018 William Khan. All rights reserved.
//

#include "DataWriter.hpp"

DataWriter::DataWriter(std::string path, std::string file_name)
{
    std::string file_source = path + "/" + file_name;
    output_file.open(file_source);
    
}
auto DataWriter::WriteLine(const std::string &line) -> void {
    output_file << line << std::endl;
}

void DataWriter::WriteNewLine()
{
    output_file << std::endl;
}

void DataWriter::WriteLines(std::vector<std::string> &data)
{
    for (auto &line : data) {
        output_file << line;
    }
}

DataWriter::~DataWriter()
{
    output_file.close();
}
