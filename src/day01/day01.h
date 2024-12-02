//
// Created by leven on 12/2/2024.
//

#ifndef AOC24_DAY01_H
#define AOC24_DAY01_H
#include <map>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class day01 {
public:
    static std::map<int, std::vector<int>> processFile(const std::string &fileName) ;
    static int findDistance(const std::vector<int>& left, const std::vector<int>& right);
    static void printDistance(const std::string& file);
};

class day01Part02 {
public:
    static int findSimilarity(const std::vector<int>& left, const std::vector<int>& right);
    static void printSimilarity(const std::string& file);
};

#endif //AOC24_DAY01_H
