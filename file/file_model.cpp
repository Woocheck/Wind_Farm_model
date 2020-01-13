#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "file_model.h"

InputData::InputData(std::string filePath)
{
    _headerLinesNumber = 2;
    readFile(filePath, _headerLines, _tokensRows);
}

bool InputData::readFile(std::string filePath, std::vector <std::string> &header, std::vector <std::vector <std::string > > &data) {
    std::ifstream in(filePath.c_str());

    if(!in){
        std::cerr << "Cannot open the file: " << filePath << std::endl;
        return false;
    }

    // If this is header line, just put it into string
    // if this is data line, break it down further into
    // separate words.
    std::string temp;
    std::vector<std::string> svec;
    int linesNumber { 0 };
    
    while(std::getline(in, temp)){
        if(temp.size() > 0) {
            if(linesNumber < _headerLinesNumber) {
                header.push_back(temp);
                linesNumber++;
            } else {
                std::istringstream ss(temp);
                do {
                    std::string word;
                    ss >> word;
                    svec.push_back(word);
                } while(ss);
                data.push_back(svec);
            }
            svec.clear();
        }
    }
    in.close();
    return true;
}

std::vector<std::string> InputData::getHeader() {
    return _headerLines;
}

std::vector<std::vector <std::string> > InputData::getData() {
    return _tokensRows;
}