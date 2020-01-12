#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "file_model.h"

InputData::InputData(std::string filePath)
{
    _headerLinesNumber = 0;
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

    while(std::getline(in, temp)){
        if(temp.size() > 0) {
            if(_headerLinesNumber < 2) {
                header.push_back(temp);
                _headerLinesNumber++;
            } else {
                std::istringstream ss(temp);
                do {
                    std::string word;
                    ss >> word;
                    svec.push_back(word);
                } while(ss);
                data.push_back(svec);
            }
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