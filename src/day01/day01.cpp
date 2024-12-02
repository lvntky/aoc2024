//
// Created by leven on 12/2/2024.
//

#include <sstream>
#include <algorithm>
#include "day01.h"

std::map<int, std::vector<int>> day01::processFile(const std::string &fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file: " << fileName << '\n';
        exit(1);
    }

    std::vector<int> left;
    std::vector<int> right;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int leftVal, rightVal;
        if (iss >> leftVal >> rightVal) {
            left.push_back(leftVal);
            right.push_back(rightVal);
        } else {
            std::cerr << "Invalid line format: " << line << '\n';
        }
    }

    file.close();

    // Sort the lists
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    /*// Print the sorted lists
    std::cout << "Left (sorted): ";
    for (int num : left) std::cout << num << " ";
    std::cout << "\nRight (sorted): ";
    for (int num : right) std::cout << num << " ";
    std::cout << '\n';

    // Calculate and print the Manhattan distance
    int distance = findDistance(left, right);
    if (distance >= 0) {
        std::cout << "distance: " << distance << '\n';
    }*/

    std::map<int, std::vector<int>> returnMap;
    returnMap[0] = left;
    returnMap[1] = right;

    return returnMap;
}

int day01::findDistance(const std::vector<int>& left, const std::vector<int>& right) {
    if (left.size() != right.size()) {
        std::cerr << "Error: Vectors must have the same size to calculate distance.\n";
        return -1;
    }

    int distance = 0;
    for (size_t i = 0; i < left.size(); ++i) {
        distance += std::abs(left[i] - right[i]);
    }

    return distance;
}

void day01::printDistance(const std::string& file) {
    std::map<int, std::vector<int>> map = processFile(file);
    int distance = findDistance(map[0], map[1]);

    std::cout << "distance: " << distance << "\n";
}

int day01Part02::findSimilarity(const std::vector<int> &left, const std::vector<int> &right) {
    // Frequency map for the right list
    std::map<int, int> rightFrequency;
    for (int num : right) {
        rightFrequency[num]++;
    }

    // Calculate similarity score
    int similarityScore = 0;
    for (int num : left) {
        if (rightFrequency[num] > 0) {
            similarityScore += num * rightFrequency[num]; // Multiply value by frequency
        }
    }

    return similarityScore;
}

void day01Part02::printSimilarity(const std::string &file) {
    std::map<int, std::vector<int>> map = day01::processFile(file);
    int similarity = findSimilarity(map[0], map[1]);

    std::cout << "Similarity: " << similarity << "\n";
}

