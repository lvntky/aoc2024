//
// Created by leven on 12/2/2024.
//

#ifndef AOC24_DAY02_H
#define AOC24_DAY02_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>


class day02 {
public:
    static std::map<int, std::vector<int>> processFile(const std::string &file);

    static void printValidRows(const std::string &file);

    static bool validateSameLevel(const std::vector<int> &row);

    static bool validateAdjacent(const std::vector<int> &row);

};

class day02Part02 : public day02 {
public:
    static void printTolerated(const std::string &file);

private:
    static bool validateSameLevelTolerated(std::vector<int> &row);

    static bool validateAdjacent(std::vector<int> &row);

};

#endif //AOC24_DAY02_H
