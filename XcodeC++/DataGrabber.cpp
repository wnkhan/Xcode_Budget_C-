//
//  DataGrabber.cpp
//  XcodeC++
//
//  Created by William Khan on 6/16/18.
//  Copyright © 2018 William Khan. All rights reserved.
//

#include "DataGrabber.hpp"

DataGrabber::DataGrabber(std::string path,std::string file_name)
{
    std::string file_source = path + "/" + file_name;
    input_file.open(file_source);
}

DataGrabber::~DataGrabber()
{
    input_file.close();
}

std::string DataGrabber::GrabLine()
{
    std::string lineOfData;
    getline(input_file,lineOfData);
    return lineOfData;
}

void DataGrabber::GrabLines(std::vector<std::string> &data)
{
    std::string line;
    while(getline(input_file,line))
    {
        data.push_back(line);
    }

}
