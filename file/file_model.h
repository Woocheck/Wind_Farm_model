#ifndef _INPUT_DATA_FILE_
#define _INPUT_DATA_FILE_

#include <string>
#include <vector>

class InputData
{
private:
    int _headerLinesNumber;
    std::vector<std::string> _headerLines;
    std::vector<std::vector<std::string>>  _tokensRows;  
public:
    InputData();
    ~InputData();
    std::vector<std::string> getHeader();
    std::vector<std::vector<std::string>> getData();
};

InputData::InputData()
{
}

InputData::~InputData()
{
}


#endif 
