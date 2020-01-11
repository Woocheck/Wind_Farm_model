#ifndef _INPUT_DATA_FILE_
#define _INPUT_DATA_FILE_

#include <string>
#include <vector>

class InputData
{
private:
    int _headerLinesNumber;
    std::vector<std::string> _headerLines;
    std::vector<std::vector<std::string> >  _tokensRows;
    bool readFile(std::string filePath, std::vector<std::string>&, std::vector< std::vector <std::string> >&);
public:
    InputData(std::string filePath);
    std::vector<std::string> getHeader();
    std::vector<std::vector<std::string>> getData();
};

#endif 
