//
// Created by leven on 12/3/2024.
//

#include "day03.h"
#define MULTIPLY_REGEX "mul\\(\\d+,\\d+\\)"

void day03::printMultiply(const std::string& file) {
    std::cout << "Part 1\n";
    std::vector<std::string> lines = AocUtils::readFileLines(file);
    std::vector<std::string> matched;

    for (const auto & line : lines) {
        std::vector<std::string> matches = AocUtils::regexMatch(line, MULTIPLY_REGEX);
        matched.insert(matched.end(), matches.begin(), matches.end());
    }
    for (const auto& match : matched) {
        std::cout << match << std::endl;
    }

    int multiply = matchProduct(matched);

    std::cout << "Multiply: " << multiply << "\n";
}

int day03::matchProduct(const std::vector<std::string>& match) {
    int sum = 0;

    for (const auto& m : match) {
        // Extract numbers from "mul(x,y)"
        int x, y;
        if (sscanf(m.c_str(), "mul(%d,%d)", &x, &y) == 2) {
            sum += x * y; // Multiply the numbers and add to sum
        }
    }

    return sum;
}
