//
// Created by leven on 12/3/2024.
//

#ifndef ADVENTOFCODE2024_DAY03_H
#define ADVENTOFCODE2024_DAY03_H

#include "../../include/AocUtils.h"

class day03 {
public:
    static void printMultiply(const std::string& file);
    static int matchProduct(const std::vector<std::string>& match);

};

class day03Part02 : day03 {
public:
    static void printMultiplyConditional(const std::string& file);
};


#endif //ADVENTOFCODE2024_DAY03_H
