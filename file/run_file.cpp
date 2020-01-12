//
// Created by trochej on 1/11/20.
//

#include <iostream>
#include "file_model.h"

int main(int argc, char**argv) {
    InputData data("test_data");
    auto header = data.getHeader();
    for (auto x : header ){
        std::cout << x << ' ' << std::endl;
    }
    auto dataRows = data.getData();
    for (auto x : dataRows) {
        for (auto y : x) {
            std::cout << y << ' ';
        }
        std::cout << std::endl;
    }
}