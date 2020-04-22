//
// Created by trochej on 1/11/20.
//

#include <iostream>
#include <memory>
#include "file_model.h"

int main(int argc, char**argv) {
    InputData data("test_data");
    
    auto dataPointer { std::make_shared<InputData>( data )};
    
    for (auto x : dataPointer->getHeader() ){
        std::cout << x << ' ' << std::endl;
    }
    
    for (auto x : dataPointer->getData()) {
        for (auto y : x) {
            std::cout << y << ' ';
        }
        std::cout << std::endl;
    }
}