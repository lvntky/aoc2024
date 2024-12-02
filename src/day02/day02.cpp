#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include "day02.h"


std::map<int, std::vector<int>> day02::processFile(const std::string &fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file: " << fileName << '\n';
        exit(1);
    }

    std::string line;
    std::map<int, std::vector<int>> rows;
    int rowIndex = 0;
    while (std::getline(file, line)) {
        std::istringstream iss(line); // Pass the line to the stringstream
        int number;
        std::vector<int> numbers;

        while (iss >> number) {
            numbers.push_back(number);
        }

        rows[rowIndex++] = numbers;
    }

    return rows;
}

bool day02::validateSameLevel(const std::vector<int> &row) {
    bool isIncreasing = row[1] > row[0]; // Decide if the sequence is increasing based on the first two numbers

    for (int i = 1; i < row.size(); ++i) {
        int difference = row[i] - row[i - 1];
        if ((isIncreasing && difference <= 0) || (!isIncreasing && difference >= 0)) {
            return false; // Sequence is not consistently increasing or decreasing
        }
    }
    return true; // All numbers are either increasing or decreasing
}

bool day02::validateAdjacent(const std::vector<int> &row) {
    for (int i = 1; i < row.size(); ++i) {
        int adjacentDifference = std::abs(row[i] - row[i - 1]);
        if (adjacentDifference < 1 || adjacentDifference > 3) {
            return false; // Adjacent difference is out of the valid range
        }
    }
    return true; // All adjacent differences are within the valid range
}

void day02::printValidRows(const std::string &file) {
    int validCount = 0;
    std::map<int, std::vector<int>> rows = processFile(file);

    for (const auto &pair: rows) {
        int rowIndex = pair.first;
        const std::vector<int> &row = pair.second;

        if (!validateAdjacent(row)) {
            std::cout << rowIndex << " - invalid adjacent\n";
            continue;
        }

        if (!validateSameLevel(row)) {
            std::cout << rowIndex << " - invalid level\n";
            continue;
        }

        validCount++;
    }

    std::cout << "Valid count: " << validCount << "\n";
}


bool isSafe(const std::vector<int> &levels) {
    bool increasing = true, decreasing = true;

    for (size_t i = 1; i < levels.size(); ++i) {
        int diff = levels[i] - levels[i - 1];
        if (std::abs(diff) < 1 || std::abs(diff) > 3) return false; // Rule violation
        if (diff > 0) decreasing = false; // Not strictly decreasing
        if (diff < 0) increasing = false; // Not strictly increasing
    }

    return increasing || decreasing;
}

// Function to check if a report is safe with the Problem Dampener
bool isSafeWithDampener(const std::vector<int> &levels) {
    if (isSafe(levels)) return true; // Already safe

    // Only create the modified vector when necessary
    for (size_t i = 0; i < levels.size(); ++i) {
        std::vector<int> modifiedLevels;

        // Create a new vector without the i-th element
        modifiedLevels.reserve(levels.size() - 1);
        modifiedLevels.insert(modifiedLevels.end(),
                              levels.begin(),
                              levels.begin() + i);
        modifiedLevels.insert(modifiedLevels.end(),
                              levels.begin() + i + 1,
                              levels.end());

        if (isSafe(modifiedLevels)) return true; // Safe after removing one level
    }
    return false; // Still unsafe
}

void day02Part02::printTolerated(const std::string &file) {
    int toleratedCount = 0;
    std::map<int, std::vector<int>> map = day02::processFile(file);

    for (const auto &[key, value]: map) {
        if (isSafeWithDampener(value)) {
            toleratedCount++;
        }
    }

    std::cout << "Tolerated count: " << toleratedCount << "\n";
}

bool day02Part02::validateSameLevelTolerated(std::vector<int> &row) {
    if (!validateAdjacent(row)) {
        return false;
    }
    int levelCounter = 0;
    bool isIncreasing = row[1] > row[0]; // Decide if the sequence is increasing based on the first two numbers

    for (int i = 1; i < row.size(); ++i) {
        int difference = row[i] - row[i - 1];
        if ((isIncreasing && difference <= 0) || (!isIncreasing && difference >= 0)) {
            levelCounter++;
        }
        if (levelCounter > 1) {
            return false;
        }
    }
    return true;
}

bool day02Part02::validateAdjacent(std::vector<int> &row) {
    // Remove consecutive duplicates
    auto it = std::unique(row.begin(), row.end());
    row.erase(it, row.end());

    // Check if all adjacent differences are valid
    for (size_t i = 1; i < row.size(); ++i) {
        int adjacentDifference = std::abs(row[i] - row[i - 1]);
        if (adjacentDifference < 1 || adjacentDifference > 3) {
            return false; // Invalid difference found
        }
    }

    return true; // All adjacent differences are valid
}