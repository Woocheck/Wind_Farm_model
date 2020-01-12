//
// Created by trochej on 1/11/20.
//

#include <iostream>
#include "file_model.h"

int main(int argc, char**argv) {
    InputData data("test_data");
    for (auto x : data.getHeader()){
        std::cout << x << ' ' << std::endl;
    }
    for (auto x : data.getHeader()) {
        for (auto y : x) {
            std::cout << y << ' ';
        }
        std::cout << std::endl;
    }
}