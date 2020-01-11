//
// Created by trochej on 1/11/20.
//

#include <iostream>
#include "file_model.h"

int main(int argc, char**argv) {
    InputData *d = new InputData("test_data");
    for (auto x : d->getHeader()){
        std::cout << x << ' ' << std::endl;
    }
    for (auto x : d->getData()) {
        for (auto y : x) {
            std::cout << y << ' ';

        }
    }
}